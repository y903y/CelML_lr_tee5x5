#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(int argc, char **argv);

int main(int argc, char **argv)
{

	int *xleft;
	int *xright;
	int *meshlistT2;
	int *meshlistT3;
	int *meshlistT1;

	readcsvint(&xleft,
			   "model/StructuredRecMLPDE/sample6/xleft_sample6.csv");
	readcsvint(&xright,
			   "model/StructuredRecMLPDE/sample6/xright_sample6.csv");
	if (rank == 0) {

		readcsvint(&meshlistT2, "meshlist_T2_0.csv");
		readcsvint(&meshlistT3, "meshlist_T3_0.csv");
		readcsvint(&meshlistT1, "meshlist_T1_0.csv");
		for (n = 0; (n < 1000); n++) {

			for (__i = 0; (__i < 1); __i++) {

				__meshnum = meshlistT2[__i];
				v[n][xleft[__meshnum]] = v[n][__meshnum];


			}


			for (__i = 0; (__i < 0); __i++) {

				__meshnum = meshlistT3[__i];
				v[n][xright[__meshnum]] = v[n][__meshnum];


			}


			senddata_0_1[0] = v[n][500];
			mpiSend(senddata_0_1, 0, 1);
			mpiRecv(recvdata_0_1, 0, 1);
			mpiWait(1);
			v[n][501] = recvdata_0_1[0];
			for (__i = 0; (__i < 500); __i++) {

				__meshnum = meshlistT1[__i];
				zz[n][__meshnum] =
					(((n < (double) 10)
					  && __meshnum ==
					  (double) 1) ? (double) 1.0 : (double) 0.0);
				r[n][__meshnum] =
					(v[n][__meshnum] * v[n][__meshnum] * v[n][__meshnum]);
				v[(n + 1)][__meshnum] =
					(v[n][__meshnum] +
					 (((((v[n][__meshnum] -
						  (r[n][__meshnum] / (double) 3)) -
						 w[n][__meshnum]) + zz[n][__meshnum]) -
					   ((D *
						 ((v[n][xright[__meshnum]] +
						   v[n][xleft[__meshnum]]) -
						  ((double) 2 * v[n][__meshnum]))) / (dx * dx))) *
					  dt));
				w[(n + 1)][__meshnum] =
					(w[n][__meshnum] +
					 (e * ((v[n][__meshnum] + b) - (g * w[n][__meshnum])) *
					  dt));


			}



		}


	}

	if (rank == 1) {

		readcsvint(&meshlistT2, "meshlist_T2_1.csv");
		readcsvint(&meshlistT3, "meshlist_T3_1.csv");
		readcsvint(&meshlistT1, "meshlist_T1_1.csv");
		for (n = 0; (n < 1000); n++) {

			for (__i = 0; (__i < 0); __i++) {

				__meshnum = meshlistT2[__i];
				v[n][xleft[__meshnum]] = v[n][__meshnum];


			}


			for (__i = 0; (__i < 1); __i++) {

				__meshnum = meshlistT3[__i];
				v[n][xright[__meshnum]] = v[n][__meshnum];


			}


			senddata_1_0[0] = v[n][501];
			mpiSend(senddata_1_0, 1, 0);
			mpiRecv(recvdata_1_0, 1, 0);
			mpiWait(0);
			v[n][500] = recvdata_1_0[0];
			for (__i = 0; (__i < 500); __i++) {

				__meshnum = meshlistT1[__i];
				zz[n][__meshnum] =
					(((n < (double) 10)
					  && __meshnum ==
					  (double) 1) ? (double) 1.0 : (double) 0.0);
				r[n][__meshnum] =
					(v[n][__meshnum] * v[n][__meshnum] * v[n][__meshnum]);
				v[(n + 1)][__meshnum] =
					(v[n][__meshnum] +
					 (((((v[n][__meshnum] -
						  (r[n][__meshnum] / (double) 3)) -
						 w[n][__meshnum]) + zz[n][__meshnum]) -
					   ((D *
						 ((v[n][xright[__meshnum]] +
						   v[n][xleft[__meshnum]]) -
						  ((double) 2 * v[n][__meshnum]))) / (dx * dx))) *
					  dt));
				w[(n + 1)][__meshnum] =
					(w[n][__meshnum] +
					 (e * ((v[n][__meshnum] + b) - (g * w[n][__meshnum])) *
					  dt));


			}



		}


	}


	return 0;
}
