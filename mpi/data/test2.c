#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/***mpiのヘッダ追加**/
#include"mpi.h"

typedef struct mpi {
	/**自身のランクを保持する変数*/
	int myrank;
	/**ノード数を保持する変数*/
	int nodenum;
	/*MPIのステータスを保持する変数*/
	MPI_Status sendStatus;
	MPI_Status recvStatus;
	/*通信のタグ識別子を保持する変数*/
	int tag;
	/*rootを親ノードとして指定*/
	int root;
	/**request waitで待つときに必要*/
	MPI_Request sendReqs;
	MPI_Request recvReqs;

	/**sendのデータを格納するための配列*/
	double* senddata;
	/**recvのデータを格納するための配列*/
	double* recvdata;
} MPI;

void mpiRecv(double *data, int num, int recvNum, struct mpi* p);
void mpiSend(double *data, int num, int recvNum, struct mpi* p);
void readcsvint(int**, char*);

int main(int argc, char **argv);

int main(int argc, char **argv) {

	/**
	 * MPIの構造体宣言
	 */
	MPI p;
	p.tag = 0;
	p.root = 0;
	int *xleft;
	int *xright;
	int *meshlistT2;
	int *meshlistT3;
	int *meshlistT1;
	/**
	 *宣言部分追加
	 */
	double v[2][1002] = { 0.0 };
	double w[2][1002] = { 0.0 };
	double r[2][1002] = { 0.0 };
	double zz[2][1002] = { 0.0 };
	double D = -0.05;
	double e = 0.002;
	double b = 1.5;
	double g = 0.3;
	double dt = 0.01;
	double dx = 0.1;
	int n;
	int __i;
	int __meshnum;
	/*********************************/

	/**MPI 初期化*/
	MPI_Init(&argc, &argv);
	/**MPI ランクを取得*/
	MPI_Comm_rank(MPI_COMM_WORLD, &(p.myrank));
	int rank = p.myrank;
	/**クラスタの台数取得*/
	MPI_Comm_size(MPI_COMM_WORLD, &(p.nodenum));
	int nodenum = p.nodenum;
	//送信と受信をするので全てのノードの数*2分確保
	//p.reqs = (MPI_Request*) malloc(sizeof(MPI_Request) * nodenum * 2);

	readcsvint(&xleft, "./xleft_sample6.csv");
	readcsvint(&xright, "./xright_sample6.csv");
	if (rank == 0) {
		readcsvint(&meshlistT2, "meshlist_T2_0.csv");
		readcsvint(&meshlistT3, "meshlist_T3_0.csv");
		readcsvint(&meshlistT1, "meshlist_T1_0.csv");
		for (n = 0; (n < 1000); n++) {

			for (__i = 0; (__i < 1); __i++) {

				__meshnum = meshlistT2[__i];
				v[n % 2][xleft[__meshnum]] = v[n % 2][__meshnum];

			}

			for (__i = 0; (__i < 0); __i++) {

				__meshnum = meshlistT3[__i];
				v[n % 2][xright[__meshnum]] = v[n % 2][__meshnum];

			}

			//送るべき数に従ってmalloc
			int sendnum = 1;
			p.senddata = (double*) malloc(sizeof(double) * sendnum);
			//double senddata_0_1[0] = v[n%2][500];
			*(p.senddata) = v[n % 2][500];
			/**********送るべき配列の作成*****************/

			/**send 1番のノードに1つだけ送る**/
			mpiSend(p.senddata, sendnum, 1, &p);

			/**recv 1番のノードからひとつ受け取る**/
			int recvnum = 1;
			p.recvdata = (double*) malloc(sizeof(double) * sendnum);
			mpiRecv(p.recvdata, recvnum, 1, &p);

			MPI_Wait(&p.recvReqs, &p.recvStatus); //受信用
			MPI_Wait(&p.sendReqs, &p.sendStatus); //受信用
			v[n % 2][501] = *(p.recvdata);
			for (__i = 0; (__i < 500); __i++) {

				__meshnum = meshlistT1[__i];
				zz[n % 2][__meshnum] = (
						((n < (double) 10) && __meshnum == (double) 1) ?
								(double) 1.0 : (double) 0.0);
				r[n % 2][__meshnum] = (v[n % 2][__meshnum] * v[n % 2][__meshnum]
						* v[n % 2][__meshnum]);
				v[(n + 1)][__meshnum] = (v[n % 2][__meshnum]
						+ (((((v[n % 2][__meshnum]
								- (r[n % 2][__meshnum] / (double) 3))
								- w[n % 2][__meshnum]) + zz[n % 2][__meshnum])
								- ((D
										* ((v[n % 2][xright[__meshnum]]
												+ v[n % 2][xleft[__meshnum]])
												- ((double) 2
														* v[n % 2][__meshnum])))
										/ (dx * dx))) * dt));
				w[(n + 1)][__meshnum] = (w[n % 2][__meshnum]
						+ (e
								* ((v[n % 2][__meshnum] + b)
										- (g * w[n % 2][__meshnum])) * dt));

			}
			free(p.recvdata);
			free(p.senddata);

		}

	}

	if (rank == 1) {

		readcsvint(&meshlistT2, "meshlist_T2_1.csv");
		readcsvint(&meshlistT3, "meshlist_T3_1.csv");
		readcsvint(&meshlistT1, "meshlist_T1_1.csv");
		for (n = 0; (n < 1000); n++) {

			for (__i = 0; (__i < 0); __i++) {

				__meshnum = meshlistT2[__i];
				v[n % 2][xleft[__meshnum]] = v[n % 2][__meshnum];

			}

			for (__i = 0; (__i < 1); __i++) {

				__meshnum = meshlistT3[__i];
				v[n % 2][xright[__meshnum]] = v[n % 2][__meshnum];

			}
			//送るべき数に従ってmalloc
			int sendnum = 1;
			p.senddata = (double*) malloc(sizeof(double) * sendnum);
			//double senddata_0_1[0] = v[n%2][500];
			*(p.senddata) = v[n % 2][501];
			/**********送るべき配列の作成*****************/

			/**send 1番のノードに1つだけ送る**/
			mpiSend(p.senddata, sendnum, 1, &p);

			/**recv 1番のノードからひとつ受け取る**/
			int recvnum = 1;
			p.recvdata = (double*) malloc(sizeof(double) * sendnum);
			mpiRecv(p.recvdata, recvnum, 1, &p);

			MPI_Wait(&p.recvReqs, &p.recvStatus); //受信用
			MPI_Wait(&p.sendReqs, &p.sendStatus); //受信用
			v[n % 2][500] = *(p.recvdata);

			//senddata_1_0[0] = v[n%2][501];
			//mpiSend(senddata_1_0, 1, 0);
			//mpiRecv(recvdata_1_0, 1, 0);
			//mpiWait(0);
			//v[n%2][500] = recvdata_1_0[0];
			for (__i = 0; (__i < 500); __i++) {

				__meshnum = meshlistT1[__i];
				zz[n % 2][__meshnum] = (
						((n % 2 < (double) 10) && __meshnum == (double) 1) ?
								(double) 1.0 : (double) 0.0);
				r[n % 2][__meshnum] = (v[n % 2][__meshnum] * v[n % 2][__meshnum]
						* v[n % 2][__meshnum]);
				v[(n + 1)%2][__meshnum] =
				(v[n%2][__meshnum]
				+ (((((v[n%2][__meshnum]
														- (r[n%2][__meshnum] / (double) 3))
												- w[n%2][__meshnum]) + zz[n%2][__meshnum])
								- ((D
												* ((v[n%2][xright[__meshnum]]
																+ v[n%2][xleft[__meshnum]])
														- ((double) 2
																* v[n%2][__meshnum])))
										/ (dx * dx))) * dt));
				w[(n % 2 + 1)][__meshnum] = (w[n % 2][__meshnum]
						+ (e
								* ((v[n % 2][__meshnum] + b)
										- (g * w[n % 2][__meshnum])) * dt));

			}
			free(p.recvdata);
			free(p.senddata);
		}

	}
	MPI_Finalize();
	return 0;
}

/***
 *
 * mpi送信用関数
 * @param data 送る配列
 * @param num  送る数
 * @param sendNum 送りたいノード番号
 *
 *
 * */

void mpiSend(double *data, int num, int sendNum, struct mpi* p) {
	//int p.tag = 0;
	MPI_Isend(data, num, MPI_DOUBLE, sendNum, p->tag, MPI_COMM_WORLD,
			&(p->sendReqs));
}

/***
 *
 * mpi受信用関数
 * @param data 受け取ったデータの格納先（配列）
 * @param num  受け取る数
 * @param sendNum 受け取りたいノード番号
 * @return 受け取りに成功したかのステータス
 *
 * */

void mpiRecv(double *data, int num, int recvNum, struct mpi* p) {
	//int tag = 0;
	MPI_Irecv(data, num, MPI_DOUBLE, recvNum, p->tag, MPI_COMM_WORLD,
			&(p->recvReqs));

}

void readcsvint(int **vec, char *filename) {
	FILE *fp;
	int linenum = 0;
	int *array;
	char buf[256];

	if ((fp = fopen(filename, "r")) == NULL ) {
		fprintf(stderr, "can't open %s\n", filename);
		exit(1);
	}

	while (fgets(buf, 256, fp) != NULL ) {
		linenum++;
	}

	array = *vec = (int *) malloc(linenum * sizeof(int));

	fseek(fp, 0L, SEEK_SET);

	while (fscanf(fp, "%d", array) != EOF) {
		array++;
	}

	fclose(fp);

	return;
}

