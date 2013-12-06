 /*
 * LR1_FTCS_30x30.c
 *
 * Generated on: 2013/05/29
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*mpiライブラリのインクルード*/
#include "mpi.h"
#define __MAX_TIME_NUM 500.0
/*REVISION: compute the number of data from the morphology + boundary points */
#define __MAX_DATA_NUM 10000
#define __MAX_MATERIAL_NUM 9604


int main ( int argc , char** argv ) ;

int main ( int argc , char** argv ) {

	/*自身のランクを保持する変数*/
	int myrank;
	/*ノード数を保持する変数*/
	int nodenum;
	/*MPI_Isend,Irecv用のリクエスト*/
	MPI_Request reqs[4];
	/*MPIのステータスを保持する変数*/
	MPI_Status recv_status, status;
	/*通信のタグ識別子を保持する変数*/
	int tag = 0;
	/*計算範囲*/
	int calcindex;
	/*各ノードの演算を行う範囲の最初の添字を保持する変数*/
	int sourcebuf;
	/*各ノードの演算を行う範囲の最後の添字を保持する変数*/
	int mycalc;
	/*rootを親ノードとして指定*/
	const int root=0;

	/*時間計測用変数*/
	double st, en, con1, con2;

	/*MPI 初期化*/
	MPI_Init(&argc,&argv);
	/*MPI ランクを取得*/
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	/*クラスタの台数取得*/
	MPI_Comm_size(MPI_COMM_WORLD,&nodenum);


	/*MPIの計算部分指定*/
	calcindex = __MAX_DATA_NUM/nodenum;
	mycalc = ((calcindex * myrank) + calcindex) - 1;
	if(__MAX_DATA_NUM % nodenum != 0 && myrank == nodenum - 1) mycalc += __MAX_DATA_NUM % nodenum;
	if(calcindex == 0) {
		printf("ノード数が多すぎ今のところ対応していません\n");
		return -1;
	}
	sourcebuf = calcindex * myrank;

	double* V0end;
	double* V1end;
	double* X0end;
	double* X1end;
	double* fast_sodium_current_E_Na__n;
	double* fast_sodium_current_h__n;
	double* fast_sodium_current_h__n1;
	double* fast_sodium_current_h_gate_alpha_h__n;
	double* fast_sodium_current_h_gate_beta_h__n;
	double* fast_sodium_current_j__n;
	double* fast_sodium_current_j__n1;
	double* fast_sodium_current_j_gate_alpha_j__n;
	double* fast_sodium_current_j_gate_beta_j__n;
	double* fast_sodium_current_m__n;
	double* fast_sodium_current_m__n1;
	double* fast_sodium_current_m_gate_alpha_m__n;
	double* fast_sodium_current_m_gate_beta_m__n;
	/*Revision*/
//	int i;
//	int n;
	double* membrane_I_stim__n;
	double* membrane_V__n;
	double* membrane_V__n1;
	double* membrane_i_K1__n;
	double* membrane_i_K__n;
	double* membrane_i_Kp__n;
	double* membrane_i_Na__n;
	double* membrane_i_b__n;
	double* membrane_i_si__n;
	/*Revision*/
	double membrane_time;
	double* plateau_potassium_current_E_Kp__n;
	double* plateau_potassium_current_Kp__n;
	double* slow_inward_current_Cai__n;
	double* slow_inward_current_Cai__n1;
	double* slow_inward_current_E_si__n;
	double* slow_inward_current_d__n;
	double* slow_inward_current_d__n1;
	double* slow_inward_current_d_gate_alpha_d__n;
	double* slow_inward_current_d_gate_beta_d__n;
	double* slow_inward_current_f__n;
	double* slow_inward_current_f__n1;
	double* slow_inward_current_f_gate_alpha_f__n;
	double* slow_inward_current_f_gate_beta_f__n;
	double* time_dependent_potassium_current_E_K__n;
	double* time_dependent_potassium_current_X__n;
	double* time_dependent_potassium_current_X__n1;
	double* time_dependent_potassium_current_X_gate_alpha_X__n;
	double* time_dependent_potassium_current_X_gate_beta_X__n;
	double* time_dependent_potassium_current_Xi__n;
	double* time_dependent_potassium_current_g_K__n;
	double* time_independent_potassium_current_E_K1__n;
	double* time_independent_potassium_current_K1_gate_alpha_K1__n;
	double* time_independent_potassium_current_K1_gate_beta_K1__n;
	double* time_independent_potassium_current_K1_infinity__n;
	double* time_independent_potassium_current_g_K1__n;
	double membrane_D;
	double membrane_R;
	double membrane_T;
	double membrane_F;
	double membrane_C;
	double membrane_stim_start;
	double membrane_stim_end;
	double membrane_stim_period;
	double membrane_stim_duration;
	double membrane_stim_amplitude;
	double fast_sodium_current_g_Na;
	double background_current_g_b;
	double time_dependent_potassium_current_g_Kbar;
	double time_dependent_potassium_current_Nai;
	double time_dependent_potassium_current_Nao;
	double plateau_potassium_current_g_Kp;
	double background_current_E_b;
	double time_independent_potassium_current_Ki;
	double time_independent_potassium_current_Ko;
	double time_dependent_potassium_current_PR_NaK;
	double deltat;
	double deltax1;
	double deltax2;

	double* __flag__n;

	int __i;

	V0end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	V1end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	X0end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	X1end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_E_Na__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_h__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_h_gate_alpha_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_h_gate_beta_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_j__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_j_gate_alpha_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_j_gate_beta_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_m__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_m_gate_alpha_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	fast_sodium_current_m_gate_beta_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_I_stim__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_V__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_V__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_Na__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_b__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	membrane_i_si__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	/*Revision*/
	plateau_potassium_current_E_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	plateau_potassium_current_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_Cai__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_Cai__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_E_si__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_d__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_d_gate_alpha_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_d_gate_beta_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_f__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_f_gate_alpha_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	slow_inward_current_f_gate_beta_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_E_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_X__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_X_gate_alpha_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_X_gate_beta_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_Xi__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_dependent_potassium_current_g_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_independent_potassium_current_E_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_independent_potassium_current_K1_gate_alpha_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_independent_potassium_current_K1_gate_beta_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_independent_potassium_current_K1_infinity__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );
	time_independent_potassium_current_g_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );

	__flag__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  );

	/*Revision: insert the initial values and change value of diffusion constant to 0.1*/
	membrane_D = (double)0.1;
	membrane_R = (double)8314.0;
	membrane_T = (double)310;
	membrane_F = (double)96484.6;
	membrane_C = (double)1;
	membrane_stim_start = (double)10; //default = 100
	membrane_stim_end = (double)100000000;
	membrane_stim_period = (double)1000;
	membrane_stim_duration = (double)10;
	membrane_stim_amplitude = (double)-25.5;
	fast_sodium_current_g_Na = (double)23;
	background_current_g_b = (double)0.03921;
	time_dependent_potassium_current_g_Kbar = 0.282;
	time_dependent_potassium_current_Nai = (double)18;
	time_dependent_potassium_current_Nao = (double)140;
	time_independent_potassium_current_Ki = (double)145;
	time_independent_potassium_current_Ko = (double)5.4;
	plateau_potassium_current_g_Kp = (double)0.0183;
	background_current_E_b = (double)-59.87;
	time_dependent_potassium_current_PR_NaK = (double)0.01833;
	deltat = 0.01;
	deltax1 = 1;
	deltax2 = 1;

	int flag__nSize = __MAX_DATA_NUM;
	for (__i = 0; __i < flag__nSize; __i++) {
		__flag__n[__i] = 1;
	}

	for (__i = 0; __i < 100; __i++) {
		__flag__n[__i] = 0;
	}
	__flag__n[100] = 0;
	__flag__n[200] = 0;
	__flag__n[300] = 0;
	__flag__n[400] = 0;
	__flag__n[500] = 0;
	__flag__n[600] = 0;
	__flag__n[700] = 0;
	__flag__n[800] = 0;
	__flag__n[900] = 0;
	__flag__n[1000] = 0;
	__flag__n[1100] = 0;
	__flag__n[1200] = 0;
	__flag__n[1300] = 0;
	__flag__n[1400] = 0;
	__flag__n[1500] = 0;
	__flag__n[1600] = 0;
	__flag__n[1700] = 0;
	__flag__n[1800] = 0;
	__flag__n[1900] = 0;
	__flag__n[2000] = 0;
	__flag__n[2100] = 0;
	__flag__n[2200] = 0;
	__flag__n[2300] = 0;
	__flag__n[2400] = 0;
	__flag__n[2500] = 0;
	__flag__n[2600] = 0;
	__flag__n[2700] = 0;
	__flag__n[2800] = 0;
	__flag__n[2900] = 0;
	__flag__n[3000] = 0;
	__flag__n[3100] = 0;
	__flag__n[3200] = 0;
	__flag__n[3300] = 0;
	__flag__n[3400] = 0;
	__flag__n[3500] = 0;
	__flag__n[3600] = 0;
	__flag__n[3700] = 0;
	__flag__n[3800] = 0;
	__flag__n[3900] = 0;
	__flag__n[4000] = 0;
	__flag__n[4100] = 0;
	__flag__n[4200] = 0;
	__flag__n[4300] = 0;
	__flag__n[4400] = 0;
	__flag__n[4500] = 0;
	__flag__n[4600] = 0;
	__flag__n[4700] = 0;
	__flag__n[4800] = 0;
	__flag__n[4900] = 0;
	__flag__n[5000] = 0;
	__flag__n[5100] = 0;
	__flag__n[5200] = 0;
	__flag__n[5300] = 0;
	__flag__n[5400] = 0;
	__flag__n[5500] = 0;
	__flag__n[5600] = 0;
	__flag__n[5700] = 0;
	__flag__n[5800] = 0;
	__flag__n[5900] = 0;
	__flag__n[6000] = 0;
	__flag__n[6100] = 0;
	__flag__n[6200] = 0;
	__flag__n[6300] = 0;
	__flag__n[6400] = 0;
	__flag__n[6500] = 0;
	__flag__n[6600] = 0;
	__flag__n[6700] = 0;
	__flag__n[6800] = 0;
	__flag__n[6900] = 0;
	__flag__n[7000] = 0;
	__flag__n[7100] = 0;
	__flag__n[7200] = 0;
	__flag__n[7300] = 0;
	__flag__n[7400] = 0;
	__flag__n[7500] = 0;
	__flag__n[7600] = 0;
	__flag__n[7700] = 0;
	__flag__n[7800] = 0;
	__flag__n[7900] = 0;
	__flag__n[8000] = 0;
	__flag__n[8100] = 0;
	__flag__n[8200] = 0;
	__flag__n[8300] = 0;
	__flag__n[8400] = 0;
	__flag__n[8500] = 0;
	__flag__n[8600] = 0;
	__flag__n[8700] = 0;
	__flag__n[8800] = 0;
	__flag__n[8900] = 0;
	__flag__n[9000] = 0;
	__flag__n[9100] = 0;
	__flag__n[9200] = 0;
	__flag__n[9300] = 0;
	__flag__n[9400] = 0;
	__flag__n[9500] = 0;
	__flag__n[9600] = 0;
	__flag__n[9700] = 0;
	__flag__n[9800] = 0;
	__flag__n[199] = 0;
	__flag__n[299] = 0;
	__flag__n[399] = 0;
	__flag__n[499] = 0;
	__flag__n[599] = 0;
	__flag__n[699] = 0;
	__flag__n[799] = 0;
	__flag__n[899] = 0;
	__flag__n[999] = 0;
	__flag__n[1099] = 0;
	__flag__n[1199] = 0;
	__flag__n[1299] = 0;
	__flag__n[1399] = 0;
	__flag__n[1499] = 0;
	__flag__n[1599] = 0;
	__flag__n[1699] = 0;
	__flag__n[1799] = 0;
	__flag__n[1899] = 0;
	__flag__n[1999] = 0;
	__flag__n[2099] = 0;
	__flag__n[2199] = 0;
	__flag__n[2299] = 0;
	__flag__n[2399] = 0;
	__flag__n[2499] = 0;
	__flag__n[2599] = 0;
	__flag__n[2699] = 0;
	__flag__n[2799] = 0;
	__flag__n[2899] = 0;
	__flag__n[2999] = 0;
	__flag__n[3099] = 0;
	__flag__n[3199] = 0;
	__flag__n[3299] = 0;
	__flag__n[3399] = 0;
	__flag__n[3499] = 0;
	__flag__n[3599] = 0;
	__flag__n[3699] = 0;
	__flag__n[3799] = 0;
	__flag__n[3899] = 0;
	__flag__n[3999] = 0;
	__flag__n[4099] = 0;
	__flag__n[4199] = 0;
	__flag__n[4299] = 0;
	__flag__n[4399] = 0;
	__flag__n[4499] = 0;
	__flag__n[4599] = 0;
	__flag__n[4699] = 0;
	__flag__n[4799] = 0;
	__flag__n[4899] = 0;
	__flag__n[4999] = 0;
	__flag__n[5099] = 0;
	__flag__n[5199] = 0;
	__flag__n[5299] = 0;
	__flag__n[5399] = 0;
	__flag__n[5499] = 0;
	__flag__n[5599] = 0;
	__flag__n[5699] = 0;
	__flag__n[5799] = 0;
	__flag__n[5899] = 0;
	__flag__n[5999] = 0;
	__flag__n[6099] = 0;
	__flag__n[6199] = 0;
	__flag__n[6299] = 0;
	__flag__n[6399] = 0;
	__flag__n[6499] = 0;
	__flag__n[6599] = 0;
	__flag__n[6699] = 0;
	__flag__n[6799] = 0;
	__flag__n[6899] = 0;
	__flag__n[6999] = 0;
	__flag__n[7099] = 0;
	__flag__n[7199] = 0;
	__flag__n[7299] = 0;
	__flag__n[7399] = 0;
	__flag__n[7499] = 0;
	__flag__n[7599] = 0;
	__flag__n[7699] = 0;
	__flag__n[7799] = 0;
	__flag__n[7899] = 0;
	__flag__n[7999] = 0;
	__flag__n[8099] = 0;
	__flag__n[8199] = 0;
	__flag__n[8299] = 0;
	__flag__n[8399] = 0;
	__flag__n[8499] = 0;
	__flag__n[8599] = 0;
	__flag__n[8699] = 0;
	__flag__n[8799] = 0;
	__flag__n[8899] = 0;
	__flag__n[8999] = 0;
	__flag__n[9099] = 0;
	__flag__n[9199] = 0;
	__flag__n[9299] = 0;
	__flag__n[9399] = 0;
	__flag__n[9499] = 0;
	__flag__n[9599] = 0;
	__flag__n[9699] = 0;
	__flag__n[9799] = 0;
	__flag__n[9899] = 0;
	for (__i = 9900; __i < 10000; __i++) {
		__flag__n[__i] = 0;
	}

	/* REVISION: initialize this special variable. TODO: indicates that arithvars in all nodes should be initialized also (set to zero?) */
	for (__i=0; __i<__MAX_DATA_NUM; __i++) {
	  time_independent_potassium_current_K1_gate_beta_K1__n[__i] = 1.0;
	}

	/*Revision: Put the initial values outside the time loop N. TODO: include in a loop.
	 * NOTE: Include the nonmaterial points since they are assigned a value also. */
	for(__i=0; __i<__MAX_DATA_NUM; __i++){
		fast_sodium_current_j__n[__i] = (double)0.98767124;
		fast_sodium_current_h__n[__i] = (double)0.9804713;
		slow_inward_current_d__n[__i] = (double)0.00316354;
		time_dependent_potassium_current_X__n[541] = (double)0.16647703;
		fast_sodium_current_m__n[__i] = (double)0.00187018;
		slow_inward_current_f__n[__i] = (double)0.99427859;
		membrane_V__n[__i] = (double)-83.853;
		slow_inward_current_Cai__n[__i] = (double)0.0002;
	}


	/* REVISION: variable for print interval */
	int timeCount = 0;

	/*Revision*/
	for(membrane_time = 0.000000; ( membrane_time <= 500.000000 ) ;membrane_time =  ( membrane_time + deltat ) ){


		//----------------------------  NO LOOP: start:null end:null ----------------------------//
//			n = (double)100;



		//----------------------------  NO LOOP: start:null end:null ----------------------------//
//			i = (double)100;

		/*ノンブロッキング通信部分*/
		//st = MPI_Wtime();
		if(myrank == root) {
			MPI_Isend(&membrane_V__n[mycalc-99], 100, MPI_DOUBLE, myrank+1, tag, MPI_COMM_WORLD, &reqs[0]);
			MPI_Irecv(&membrane_V__n[mycalc+1], 100, MPI_DOUBLE, myrank+1, tag, MPI_COMM_WORLD, &reqs[1]);
		} else if (myrank != root && myrank != nodenum-1){
			MPI_Isend(&membrane_V__n[mycalc-99], 100, MPI_DOUBLE, myrank+1, tag, MPI_COMM_WORLD, &reqs[0]);
			MPI_Isend(&membrane_V__n[sourcebuf], 100, MPI_DOUBLE, myrank-1, tag, MPI_COMM_WORLD, &reqs[1]);
			MPI_Irecv(&membrane_V__n[sourcebuf-100], 100, MPI_DOUBLE, myrank-1, tag, MPI_COMM_WORLD, &reqs[2]);
			MPI_Irecv(&membrane_V__n[mycalc+1], 100, MPI_DOUBLE, myrank+1, tag, MPI_COMM_WORLD, &reqs[3]);
		} else if (myrank == nodenum-1){
			MPI_Isend(&membrane_V__n[sourcebuf], 100, MPI_DOUBLE, myrank-1, tag, MPI_COMM_WORLD, &reqs[0]);
			MPI_Irecv(&membrane_V__n[sourcebuf-100], 100, MPI_DOUBLE, myrank-1, tag, MPI_COMM_WORLD, &reqs[1]);
		}

		/* REVISION: correct the indexing TODO: put the correct range of morphology nodes */
		//---------------------------- LOOP ----------------------------//
		//con1 = MPI_Wtime();
		for(__i = sourcebuf; __i <= mycalc; __i++){
			slow_inward_current_f_gate_beta_f__n[__i] = ( (  ( (double)0.0065 * exp(  (  ( - (double)0.02 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.2 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  ) ) * __flag__n[__i] ;
			plateau_potassium_current_Kp__n[__i] =  ( ( (double)1 /  ( (double)1 + exp(  (  ( (double)7.488 - membrane_V__n[__i] )  / (double)5.98 )  ) )  ) ) * __flag__n[__i] ;
			slow_inward_current_f_gate_alpha_f__n[__i] = ( (  ( (double)0.012 * exp(  (  ( - (double)0.008 )  *  ( membrane_V__n[__i] + (double)28 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.15 *  ( membrane_V__n[__i] + (double)28 )  )  ) )  ) ) * __flag__n[__i] ;
			slow_inward_current_d_gate_alpha_d__n[__i] = ( (  ( (double)0.095 * exp(  (  ( - (double)0.01 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.072 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  ) ) * __flag__n[__i] ;
			slow_inward_current_d_gate_beta_d__n[__i] = ( (  ( (double)0.07 * exp(  (  ( - (double)0.017 )  *  ( membrane_V__n[__i] + (double)44 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.05 *  ( membrane_V__n[__i] + (double)44 )  )  ) )  ) ) * __flag__n[__i] ;
			slow_inward_current_E_si__n[__i] = ( ( (double)7.7 -  ( (double)13.0287 * log(  ( slow_inward_current_Cai__n[__i] / (double)1 )  ) )  ) ) * __flag__n[__i] ;
			membrane_i_b__n[__i] = ( ( background_current_g_b *  ( membrane_V__n[__i] - background_current_E_b )  ) ) * __flag__n[__i] ;
			fast_sodium_current_j_gate_beta_j__n[__i] = ( (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)0.1212 * exp(  (  ( - (double)0.01052 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1378 )  *  ( membrane_V__n[__i] + (double)40.14 )  )  ) )  )  :  (  ( (double)0.3 * exp(  (  ( - (double)0.0000002535 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)32 )  )  ) )  )  ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_g_K__n[__i] = ( ( time_dependent_potassium_current_g_Kbar * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_E_K__n[__i] = ( (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  (  ( time_independent_potassium_current_Ko +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nao )  )  /  ( time_independent_potassium_current_Ki +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nai )  )  )  ) ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_X_gate_alpha_X__n[__i] = ( (  ( (double)0.0005 * exp(  ( (double)0.083 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.057 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_X_gate_beta_X__n[__i] = ( (  ( (double)0.0013 * exp(  (  ( - (double)0.06 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.04 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_Xi__n[__i] = ( (  ( membrane_V__n[__i] >  ( - (double)100 )  )  ?  (  ( (double)2.837 *  ( exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)77 )  )  ) - (double)1 )  )  /  (  ( membrane_V__n[__i] + (double)77 )  * exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)35 )  )  ) )  )  : (double)1 ) ) * __flag__n[__i] ;
			time_independent_potassium_current_g_K1__n[__i] = ( ( (double)0.6047 * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) ) ) * __flag__n[__i] ;
			time_independent_potassium_current_E_K1__n[__i] = ( (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_independent_potassium_current_Ko / time_independent_potassium_current_Ki )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_E_Na__n[__i] = ( (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_dependent_potassium_current_Nao / time_dependent_potassium_current_Nai )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_j_gate_alpha_j__n[__i] = ( (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  (  (  (  ( - (double)127140 )  * exp(  ( (double)0.2444 * membrane_V__n[__i] )  ) )  -  ( (double)0.00003474 * exp(  (  ( - (double)0.04391 )  * membrane_V__n[__i] )  ) )  )  *  ( membrane_V__n[__i] + (double)37.78 )  )  /  ( (double)1 + exp(  ( (double)0.311 *  ( membrane_V__n[__i] + (double)79.23 )  )  ) )  )  : (double)0 ) ) * __flag__n[__i] ;
			fast_sodium_current_h_gate_alpha_h__n[__i] = ( (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  ( (double)0.135 * exp(  (  ( (double)80 + membrane_V__n[__i] )  /  ( - (double)6.8 )  )  ) )  : (double)0 ) ) * __flag__n[__i] ;
			fast_sodium_current_m_gate_beta_m__n[__i] = ( ( (double)0.08 * exp(  (  ( - membrane_V__n[__i] )  / (double)11 )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_m_gate_alpha_m__n[__i] = ( (  ( (double)0.32 *  ( membrane_V__n[__i] + (double)47.13 )  )  /  ( (double)1 - exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)47.13 )  )  ) )  ) ) * __flag__n[__i] ;
			fast_sodium_current_h_gate_beta_h__n[__i] = ( (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)3.56 * exp(  ( (double)0.079 * membrane_V__n[__i] )  ) )  +  ( (double)310000 * exp(  ( (double)0.35 * membrane_V__n[__i] )  ) )  )  :  ( (double)1 /  ( (double)0.13 *  ( (double)1 + exp(  (  ( membrane_V__n[__i] + (double)10.66 )  /  ( - (double)11.1 )  )  ) )  )  )  ) ) * __flag__n[__i] ;
		}
		//con2 = MPI_Wtime();

		/*同期部分*/
		MPI_Wait(&reqs[0], &status);
		MPI_Wait(&reqs[1], &status);
		if(myrank != root && myrank != nodenum - 1) {
			MPI_Wait(&reqs[2], &status);
			MPI_Wait(&reqs[3], &status);
		}
		//en = MPI_Wtime();

		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//X0end = X0end;


		/* REVISION: correct the boundary condition equations (remove unneccessary flags) */

		//---------------------------- NODE 0 - 99 D[] ----------------------------//
		for(__i=1; __i<=98; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( __i + 100 ) ] ;
		}

		//---------------------------- NODE 100 ~ R[] ----------------------------//
			membrane_V__n[100] = membrane_V__n[ 101 ] ;
			membrane_V__n[200] = membrane_V__n[ 201 ] ;
			membrane_V__n[300] = membrane_V__n[ 301 ] ;
			membrane_V__n[400] = membrane_V__n[ 401 ] ;
			membrane_V__n[500] = membrane_V__n[ 501 ] ;
			membrane_V__n[600] = membrane_V__n[ 601 ] ;
			membrane_V__n[700] = membrane_V__n[ 701 ] ;
			membrane_V__n[800] = membrane_V__n[ 801 ] ;
			membrane_V__n[900] = membrane_V__n[ 901 ] ;
			membrane_V__n[1000] = membrane_V__n[ 1001 ] ;
			membrane_V__n[1100] = membrane_V__n[ 1101 ] ;
			membrane_V__n[1200] = membrane_V__n[ 1201 ] ;
			membrane_V__n[1300] = membrane_V__n[ 1301 ] ;
			membrane_V__n[1400] = membrane_V__n[ 1401 ] ;
			membrane_V__n[1500] = membrane_V__n[ 1501 ] ;
			membrane_V__n[1600] = membrane_V__n[ 1601 ] ;
			membrane_V__n[1700] = membrane_V__n[ 1701 ] ;
			membrane_V__n[1800] = membrane_V__n[ 1801 ] ;
			membrane_V__n[1900] = membrane_V__n[ 1901 ] ;
			membrane_V__n[2000] = membrane_V__n[ 2001 ] ;
			membrane_V__n[2100] = membrane_V__n[ 2101 ] ;
			membrane_V__n[2200] = membrane_V__n[ 2201 ] ;
			membrane_V__n[2300] = membrane_V__n[ 2301 ] ;
			membrane_V__n[2400] = membrane_V__n[ 2401 ] ;
			membrane_V__n[2500] = membrane_V__n[ 2501 ] ;
			membrane_V__n[2600] = membrane_V__n[ 2601 ] ;
			membrane_V__n[2700] = membrane_V__n[ 2701 ] ;
			membrane_V__n[2800] = membrane_V__n[ 2801 ] ;
			membrane_V__n[2900] = membrane_V__n[ 2901 ] ;
			membrane_V__n[3000] = membrane_V__n[ 3001 ] ;
			membrane_V__n[3100] = membrane_V__n[ 3101 ] ;
			membrane_V__n[3200] = membrane_V__n[ 3201 ] ;
			membrane_V__n[3300] = membrane_V__n[ 3301 ] ;
			membrane_V__n[3400] = membrane_V__n[ 3401 ] ;
			membrane_V__n[3500] = membrane_V__n[ 3501 ] ;
			membrane_V__n[3600] = membrane_V__n[ 3601 ] ;
			membrane_V__n[3700] = membrane_V__n[ 3701 ] ;
			membrane_V__n[3800] = membrane_V__n[ 3801 ] ;
			membrane_V__n[3900] = membrane_V__n[ 3901 ] ;
			membrane_V__n[4000] = membrane_V__n[ 4001 ] ;
			membrane_V__n[4100] = membrane_V__n[ 4101 ] ;
			membrane_V__n[4200] = membrane_V__n[ 4201 ] ;
			membrane_V__n[4300] = membrane_V__n[ 4301 ] ;
			membrane_V__n[4400] = membrane_V__n[ 4401 ] ;
			membrane_V__n[4500] = membrane_V__n[ 4501 ] ;
			membrane_V__n[4600] = membrane_V__n[ 4601 ] ;
			membrane_V__n[4700] = membrane_V__n[ 4701 ] ;
			membrane_V__n[4800] = membrane_V__n[ 4801 ] ;
			membrane_V__n[4900] = membrane_V__n[ 4901 ] ;
			membrane_V__n[5000] = membrane_V__n[ 5001 ] ;
			membrane_V__n[5100] = membrane_V__n[ 5101 ] ;
			membrane_V__n[5200] = membrane_V__n[ 5201 ] ;
			membrane_V__n[5300] = membrane_V__n[ 5301 ] ;
			membrane_V__n[5400] = membrane_V__n[ 5401 ] ;
			membrane_V__n[5500] = membrane_V__n[ 5501 ] ;
			membrane_V__n[5600] = membrane_V__n[ 5601 ] ;
			membrane_V__n[5700] = membrane_V__n[ 5701 ] ;
			membrane_V__n[5800] = membrane_V__n[ 5801 ] ;
			membrane_V__n[5900] = membrane_V__n[ 5901 ] ;
			membrane_V__n[6000] = membrane_V__n[ 6001 ] ;
			membrane_V__n[6100] = membrane_V__n[ 6101 ] ;
			membrane_V__n[6200] = membrane_V__n[ 6201 ] ;
			membrane_V__n[6300] = membrane_V__n[ 6301 ] ;
			membrane_V__n[6400] = membrane_V__n[ 6401 ] ;
			membrane_V__n[6500] = membrane_V__n[ 6501 ] ;
			membrane_V__n[6600] = membrane_V__n[ 6601 ] ;
			membrane_V__n[6700] = membrane_V__n[ 6701 ] ;
			membrane_V__n[6800] = membrane_V__n[ 6801 ] ;
			membrane_V__n[6900] = membrane_V__n[ 6901 ] ;
			membrane_V__n[7000] = membrane_V__n[ 7001 ] ;
			membrane_V__n[7100] = membrane_V__n[ 7101 ] ;
			membrane_V__n[7200] = membrane_V__n[ 7201 ] ;
			membrane_V__n[7300] = membrane_V__n[ 7301 ] ;
			membrane_V__n[7400] = membrane_V__n[ 7401 ] ;
			membrane_V__n[7500] = membrane_V__n[ 7501 ] ;
			membrane_V__n[7600] = membrane_V__n[ 7601 ] ;
			membrane_V__n[7700] = membrane_V__n[ 7701 ] ;
			membrane_V__n[7800] = membrane_V__n[ 7801 ] ;
			membrane_V__n[7900] = membrane_V__n[ 7901 ] ;
			membrane_V__n[8000] = membrane_V__n[ 8001 ] ;
			membrane_V__n[8100] = membrane_V__n[ 8101 ] ;
			membrane_V__n[8200] = membrane_V__n[ 8201 ] ;
			membrane_V__n[8300] = membrane_V__n[ 8301 ] ;
			membrane_V__n[8400] = membrane_V__n[ 8401 ] ;
			membrane_V__n[8500] = membrane_V__n[ 8501 ] ;
			membrane_V__n[8600] = membrane_V__n[ 8601 ] ;
			membrane_V__n[8700] = membrane_V__n[ 8701 ] ;
			membrane_V__n[8800] = membrane_V__n[ 8801 ] ;
			membrane_V__n[8900] = membrane_V__n[ 8901 ] ;
			membrane_V__n[9000] = membrane_V__n[ 9001 ] ;
			membrane_V__n[9100] = membrane_V__n[ 9101 ] ;
			membrane_V__n[9200] = membrane_V__n[ 9201 ] ;
			membrane_V__n[9300] = membrane_V__n[ 9301 ] ;
			membrane_V__n[9400] = membrane_V__n[ 9401 ] ;
			membrane_V__n[9500] = membrane_V__n[ 9501 ] ;
			membrane_V__n[9600] = membrane_V__n[ 9601 ] ;
			membrane_V__n[9700] = membrane_V__n[ 9701 ] ;
			membrane_V__n[9800] = membrane_V__n[ 9801 ] ;

		//---------------------------- NODE 199 ~ L[] ----------------------------//
			membrane_V__n[199] = membrane_V__n[ 198 ] ;
			membrane_V__n[299] = membrane_V__n[ 298 ] ;
			membrane_V__n[399] = membrane_V__n[ 398 ] ;
			membrane_V__n[499] = membrane_V__n[ 498 ] ;
			membrane_V__n[599] = membrane_V__n[ 598 ] ;
			membrane_V__n[699] = membrane_V__n[ 698 ] ;
			membrane_V__n[799] = membrane_V__n[ 798 ] ;
			membrane_V__n[899] = membrane_V__n[ 898 ] ;
			membrane_V__n[999] = membrane_V__n[ 998 ] ;
			membrane_V__n[1099] = membrane_V__n[ 1098 ] ;
			membrane_V__n[1199] = membrane_V__n[ 1198 ] ;
			membrane_V__n[1299] = membrane_V__n[ 1298 ] ;
			membrane_V__n[1399] = membrane_V__n[ 1398 ] ;
			membrane_V__n[1499] = membrane_V__n[ 1498 ] ;
			membrane_V__n[1599] = membrane_V__n[ 1598 ] ;
			membrane_V__n[1699] = membrane_V__n[ 1698 ] ;
			membrane_V__n[1799] = membrane_V__n[ 1798 ] ;
			membrane_V__n[1899] = membrane_V__n[ 1898 ] ;
			membrane_V__n[1999] = membrane_V__n[ 1998 ] ;
			membrane_V__n[2099] = membrane_V__n[ 2098 ] ;
			membrane_V__n[2199] = membrane_V__n[ 2198 ] ;
			membrane_V__n[2299] = membrane_V__n[ 2298 ] ;
			membrane_V__n[2399] = membrane_V__n[ 2398 ] ;
			membrane_V__n[2499] = membrane_V__n[ 2498 ] ;
			membrane_V__n[2599] = membrane_V__n[ 2598 ] ;
			membrane_V__n[2699] = membrane_V__n[ 2698 ] ;
			membrane_V__n[2799] = membrane_V__n[ 2798 ] ;
			membrane_V__n[2899] = membrane_V__n[ 2898 ] ;
			membrane_V__n[2999] = membrane_V__n[ 2998 ] ;
			membrane_V__n[3099] = membrane_V__n[ 3098 ] ;
			membrane_V__n[3199] = membrane_V__n[ 3198 ] ;
			membrane_V__n[3299] = membrane_V__n[ 3298 ] ;
			membrane_V__n[3399] = membrane_V__n[ 3398 ] ;
			membrane_V__n[3499] = membrane_V__n[ 3498 ] ;
			membrane_V__n[3599] = membrane_V__n[ 3598 ] ;
			membrane_V__n[3699] = membrane_V__n[ 3698 ] ;
			membrane_V__n[3799] = membrane_V__n[ 3798 ] ;
			membrane_V__n[3899] = membrane_V__n[ 3898 ] ;
			membrane_V__n[3999] = membrane_V__n[ 3998 ] ;
			membrane_V__n[4099] = membrane_V__n[ 4098 ] ;
			membrane_V__n[4199] = membrane_V__n[ 4198 ] ;
			membrane_V__n[4299] = membrane_V__n[ 4298 ] ;
			membrane_V__n[4399] = membrane_V__n[ 4398 ] ;
			membrane_V__n[4499] = membrane_V__n[ 4498 ] ;
			membrane_V__n[4599] = membrane_V__n[ 4598 ] ;
			membrane_V__n[4699] = membrane_V__n[ 4698 ] ;
			membrane_V__n[4799] = membrane_V__n[ 4798 ] ;
			membrane_V__n[4899] = membrane_V__n[ 4898 ] ;
			membrane_V__n[4999] = membrane_V__n[ 4998 ] ;
			membrane_V__n[5099] = membrane_V__n[ 5098 ] ;
			membrane_V__n[5199] = membrane_V__n[ 5198 ] ;
			membrane_V__n[5299] = membrane_V__n[ 5298 ] ;
			membrane_V__n[5399] = membrane_V__n[ 5398 ] ;
			membrane_V__n[5499] = membrane_V__n[ 5498 ] ;
			membrane_V__n[5599] = membrane_V__n[ 5598 ] ;
			membrane_V__n[5699] = membrane_V__n[ 5698 ] ;
			membrane_V__n[5799] = membrane_V__n[ 5798 ] ;
			membrane_V__n[5899] = membrane_V__n[ 5898 ] ;
			membrane_V__n[5999] = membrane_V__n[ 5998 ] ;
			membrane_V__n[6099] = membrane_V__n[ 6098 ] ;
			membrane_V__n[6199] = membrane_V__n[ 6198 ] ;
			membrane_V__n[6299] = membrane_V__n[ 6298 ] ;
			membrane_V__n[6399] = membrane_V__n[ 6398 ] ;
			membrane_V__n[6499] = membrane_V__n[ 6498 ] ;
			membrane_V__n[6599] = membrane_V__n[ 6598 ] ;
			membrane_V__n[6699] = membrane_V__n[ 6698 ] ;
			membrane_V__n[6799] = membrane_V__n[ 6798 ] ;
			membrane_V__n[6899] = membrane_V__n[ 6898 ] ;
			membrane_V__n[6999] = membrane_V__n[ 6998 ] ;
			membrane_V__n[7099] = membrane_V__n[ 7098 ] ;
			membrane_V__n[7199] = membrane_V__n[ 7198 ] ;
			membrane_V__n[7299] = membrane_V__n[ 7298 ] ;
			membrane_V__n[7399] = membrane_V__n[ 7398 ] ;
			membrane_V__n[7499] = membrane_V__n[ 7498 ] ;
			membrane_V__n[7599] = membrane_V__n[ 7598 ] ;
			membrane_V__n[7699] = membrane_V__n[ 7698 ] ;
			membrane_V__n[7799] = membrane_V__n[ 7798 ] ;
			membrane_V__n[7899] = membrane_V__n[ 7898 ] ;
			membrane_V__n[7999] = membrane_V__n[ 7998 ] ;
			membrane_V__n[8099] = membrane_V__n[ 8098 ] ;
			membrane_V__n[8199] = membrane_V__n[ 8198 ] ;
			membrane_V__n[8299] = membrane_V__n[ 8298 ] ;
			membrane_V__n[8399] = membrane_V__n[ 8398 ] ;
			membrane_V__n[8499] = membrane_V__n[ 8498 ] ;
			membrane_V__n[8599] = membrane_V__n[ 8598 ] ;
			membrane_V__n[8699] = membrane_V__n[ 8698 ] ;
			membrane_V__n[8799] = membrane_V__n[ 8798 ] ;
			membrane_V__n[8899] = membrane_V__n[ 8898 ] ;
			membrane_V__n[8999] = membrane_V__n[ 8998 ] ;
			membrane_V__n[9099] = membrane_V__n[ 9098 ] ;
			membrane_V__n[9199] = membrane_V__n[ 9198 ] ;
			membrane_V__n[9299] = membrane_V__n[ 9298 ] ;
			membrane_V__n[9399] = membrane_V__n[ 9398 ] ;
			membrane_V__n[9499] = membrane_V__n[ 9498 ] ;
			membrane_V__n[9599] = membrane_V__n[ 9598 ] ;
			membrane_V__n[9699] = membrane_V__n[ 9698 ] ;
			membrane_V__n[9799] = membrane_V__n[ 9798 ] ;
			membrane_V__n[9899] = membrane_V__n[ 9898 ] ;

		//---------------------------- NODE 9900 - 9999 U[] ----------------------------//
		for(__i=9901; __i<=9998; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( __i - 100 ) ] ;
		}



		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//X1end = X1end;



		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//V0end = V0end;



		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//V1end = V1end;



		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//membrane_time = membrane_time;


		/* REVISION: added the equation with differential equations TODO: revise the stimulation equation */
		//Shortest Calculation Order:1
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
			slow_inward_current_d__n1[__i] = ( ( slow_inward_current_d__n[__i] + deltat * (  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( (double)1 - slow_inward_current_d__n[__i] )  )  -  ( slow_inward_current_d_gate_beta_d__n[__i] * slow_inward_current_d__n[__i] )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_j__n1[__i] = ( ( fast_sodium_current_j__n[__i] + deltat * (  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( (double)1 - fast_sodium_current_j__n[__i] )  )  -  ( fast_sodium_current_j_gate_beta_j__n[__i] * fast_sodium_current_j__n[__i] )  ) ) ) * __flag__n[__i] ;
			slow_inward_current_f__n1[__i] = ( ( slow_inward_current_f__n[__i] + deltat * (  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( (double)1 - slow_inward_current_f__n[__i] )  )  -  ( slow_inward_current_f_gate_beta_f__n[__i] * slow_inward_current_f__n[__i] )  ) ) ) * __flag__n[__i] ;
			time_dependent_potassium_current_X__n1[__i] = ( ( time_dependent_potassium_current_X__n[__i] + deltat * (  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( (double)1 - time_dependent_potassium_current_X__n[__i] )  )  -  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] * time_dependent_potassium_current_X__n[__i] )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_m__n1[__i] = ( ( fast_sodium_current_m__n[__i] + deltat * (  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( (double)1 - fast_sodium_current_m__n[__i] )  )  -  ( fast_sodium_current_m_gate_beta_m__n[__i] * fast_sodium_current_m__n[__i] )  ) ) ) * __flag__n[__i] ;
			fast_sodium_current_h__n1[__i] = ( ( fast_sodium_current_h__n[__i] + deltat * (  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( (double)1 - fast_sodium_current_h__n[__i] )  )  -  ( fast_sodium_current_h_gate_beta_h__n[__i] * fast_sodium_current_h__n[__i] )  ) ) ) * __flag__n[__i] ;
			membrane_i_si__n[__i] = ( ( (double)0.09 * slow_inward_current_d__n[__i] * slow_inward_current_f__n[__i] *  ( membrane_V__n[__i] - slow_inward_current_E_si__n[__i] )  ) ) * __flag__n[__i] ;
			membrane_i_K__n[__i] = ( ( time_dependent_potassium_current_g_K__n[__i] * time_dependent_potassium_current_X__n[__i] * time_dependent_potassium_current_Xi__n[__i] *  ( membrane_V__n[__i] - time_dependent_potassium_current_E_K__n[__i] )  ) ) * __flag__n[__i] ;
			time_independent_potassium_current_K1_gate_beta_K1__n[__i] = ( (  (  ( (double)0.49124 * exp(  ( (double)0.08032 *  (  ( membrane_V__n[__i] + (double)5.476 )  - time_independent_potassium_current_E_K1__n[__i] )  )  ) )  +  ( (double)1 * exp(  ( (double)0.06175 *  ( membrane_V__n[__i] -  ( time_independent_potassium_current_E_K1__n[__i] + (double)594.31 )  )  )  ) )  )  /  ( (double)1 + exp(  (  ( - (double)0.5143 )  *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  + (double)4.753 )  )  ) )  ) ) * __flag__n[__i] ;
			plateau_potassium_current_E_Kp__n[__i] = ( time_independent_potassium_current_E_K1__n[__i] ) * __flag__n[__i] ;
			time_independent_potassium_current_K1_gate_alpha_K1__n[__i] = ( ( (double)1.02 /  ( (double)1 + exp(  ( (double)0.2385 *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  - (double)59.215 )  )  ) )  ) ) * __flag__n[__i] ;
			membrane_i_Na__n[__i] = ( ( fast_sodium_current_g_Na * pow( fast_sodium_current_m__n[__i] , (double)3 ) * fast_sodium_current_h__n[__i] * fast_sodium_current_j__n[__i] *  ( membrane_V__n[__i] - fast_sodium_current_E_Na__n[__i] )  ) ) * __flag__n[__i] ;
			/* REVISION: revise the stimulation equations apply if else TODO: see if it can be done manually, else make Istim = 0; */
			if (__i>=101 && __i<=198) {
				membrane_I_stim__n[__i] = ( (  (  ( membrane_time >= membrane_stim_start )  &&  ( membrane_time <= membrane_stim_end )  &&  (  (  ( membrane_time - membrane_stim_start )  -  ( floor(  (  ( membrane_time - membrane_stim_start )  / membrane_stim_period )  ) * membrane_stim_period )  )  <= membrane_stim_duration )  )  ? membrane_stim_amplitude : (double)0 ) ) * __flag__n[__i] ;
			} else {
				membrane_I_stim__n[__i] = ( 0 ) * __flag__n[__i] ;
			}

		}


		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:2
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
			slow_inward_current_Cai__n1[__i] = ( ( slow_inward_current_Cai__n[__i] + deltat * (  (  (  ( - (double)0.0001 )  / (double)1 )  * membrane_i_si__n[__i] )  +  ( (double)0.07 *  ( (double)0.0001 - slow_inward_current_Cai__n[__i] )  )  ) ) ) * __flag__n[__i] ;
			membrane_i_Kp__n[__i] = ( ( plateau_potassium_current_g_Kp * plateau_potassium_current_Kp__n[__i] *  ( membrane_V__n[__i] - plateau_potassium_current_E_Kp__n[__i] )  ) ) * __flag__n[__i] ;
			time_independent_potassium_current_K1_infinity__n[__i] = ( ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] /  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] + time_independent_potassium_current_K1_gate_beta_K1__n[__i] )  ) ) * __flag__n[__i] ;
		}


		//Shortest Calculation Order:3
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
			membrane_i_K1__n[__i] = ( ( time_independent_potassium_current_g_K1__n[__i] * time_independent_potassium_current_K1_infinity__n[__i] *  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  ) ) * __flag__n[__i] ;
		}


		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:4
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
			membrane_V__n1[__i]  = ( ( membrane_V__n[__i] + deltat * ( (  (  ( - (double)1 )  / membrane_C )  *  ( membrane_I_stim__n[__i] + membrane_i_Na__n[__i] + membrane_i_si__n[__i] + membrane_i_K__n[__i] + membrane_i_K1__n[__i] + membrane_i_Kp__n[__i] + membrane_i_b__n[__i] )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( __i + 1 ) ] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[ ( __i - 1 ) ] )  /  ( deltax1 * deltax1 )  )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( __i + 100 )] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[ ( __i - 100 ) ] )  /  ( deltax2 * deltax2 )  )  )  ) ) ) * __flag__n[__i] ;
		}


		/* REVISION: print current time */
		/*if (myrank == root){
			if (timeCount % ((int)(100)) == 0) {
				printf("%f ", membrane_time);
			}
		}*/

		/* REVISION: reassign the results of index n1(n+1) to index n TODO: harmonize with structured relml version */
		for(__i = sourcebuf; __i <= mycalc; __i++){
			fast_sodium_current_j__n[__i] = ( fast_sodium_current_j__n1[__i] ) * __flag__n[__i] ;
			fast_sodium_current_h__n[__i] = ( fast_sodium_current_h__n1[__i] ) * __flag__n[__i] ;
			slow_inward_current_d__n[__i] = ( slow_inward_current_d__n1[__i] ) * __flag__n[__i] ;
			time_dependent_potassium_current_X__n[__i] = ( time_dependent_potassium_current_X__n1[__i] ) * __flag__n[__i] ;
			fast_sodium_current_m__n[__i] = ( fast_sodium_current_m__n1[__i] ) * __flag__n[__i] ;
			slow_inward_current_f__n[__i] = ( slow_inward_current_f__n1[__i] ) * __flag__n[__i] ;
			membrane_V__n[__i] = ( membrane_V__n1[__i] ) * __flag__n[__i] ;

			/* REVISION: print a partial part of results (opposite ends of the morphology) */
			/*if (myrank == root){
				if (timeCount % ((int)(100)) == 0) {
					if ( __i>=980 && __i<=985) {
						printf("%f ", membrane_V__n1[__i]);
					}
					if ( __i==3000 ) {
						printf(" <--- stim start : array end ---> ");
					}
					if ( __i>=5801 && __i<=5805) {
						printf("%f ", membrane_V__n1[__i]);
					}
				}
			}*/
		}

		/* REVISION: print a partial part of results */
		/*if (myrank == root) {
			if (timeCount % ((int)(100)) == 0) {
				printf("\n");
			}
		}*/

		/*通信時間計測出力*/
		/*if(myrank == root){
			if(timeCount % 100 == 0) {
				printf("%.6f\n", en-st);
			}
		}*/

		/* REVISION: insert time counter */
		timeCount =  ( timeCount + 1 ) ;

	}

	free ( V0end ) ;
	free ( V1end ) ;
	free ( X0end ) ;
	free ( X1end ) ;
	free ( fast_sodium_current_E_Na__n ) ;
	free ( fast_sodium_current_h__n ) ;
	free ( fast_sodium_current_h__n1 ) ;
	free ( fast_sodium_current_h_gate_alpha_h__n ) ;
	free ( fast_sodium_current_h_gate_beta_h__n ) ;
	free ( fast_sodium_current_j__n ) ;
	free ( fast_sodium_current_j__n1 ) ;
	free ( fast_sodium_current_j_gate_alpha_j__n ) ;
	free ( fast_sodium_current_j_gate_beta_j__n ) ;
	free ( fast_sodium_current_m__n ) ;
	free ( fast_sodium_current_m__n1 ) ;
	free ( fast_sodium_current_m_gate_alpha_m__n ) ;
	free ( fast_sodium_current_m_gate_beta_m__n ) ;
	/* REVISION: remove free( membrane_time, i and n )*/
	free ( membrane_I_stim__n ) ;
	free ( membrane_V__n ) ;
	free ( membrane_V__n1 ) ;
	free ( membrane_i_K1__n ) ;
	free ( membrane_i_K__n ) ;
	free ( membrane_i_Kp__n ) ;
	free ( membrane_i_Na__n ) ;
	free ( membrane_i_b__n ) ;
	free ( membrane_i_si__n ) ;
	free ( plateau_potassium_current_E_Kp__n ) ;
	free ( plateau_potassium_current_Kp__n ) ;
	free ( slow_inward_current_Cai__n ) ;
	free ( slow_inward_current_Cai__n1 ) ;
	free ( slow_inward_current_E_si__n ) ;
	free ( slow_inward_current_d__n ) ;
	free ( slow_inward_current_d__n1 ) ;
	free ( slow_inward_current_d_gate_alpha_d__n ) ;
	free ( slow_inward_current_d_gate_beta_d__n ) ;
	free ( slow_inward_current_f__n ) ;
	free ( slow_inward_current_f__n1 ) ;
	free ( slow_inward_current_f_gate_alpha_f__n ) ;
	free ( slow_inward_current_f_gate_beta_f__n ) ;
	free ( time_dependent_potassium_current_E_K__n ) ;
	free ( time_dependent_potassium_current_X__n ) ;
	free ( time_dependent_potassium_current_X__n1 ) ;
	free ( time_dependent_potassium_current_X_gate_alpha_X__n ) ;
	free ( time_dependent_potassium_current_X_gate_beta_X__n ) ;
	free ( time_dependent_potassium_current_Xi__n ) ;
	free ( time_dependent_potassium_current_g_K__n ) ;
	free ( time_independent_potassium_current_E_K1__n ) ;
	free ( time_independent_potassium_current_K1_gate_alpha_K1__n ) ;
	free ( time_independent_potassium_current_K1_gate_beta_K1__n ) ;
	free ( time_independent_potassium_current_K1_infinity__n ) ;
	free ( time_independent_potassium_current_g_K1__n ) ;

	/********
	* Discretization time was 	134 s.

	* Var container creation time was 1 s.
	* Bipartite graph time was 41 s.
	* Maximum matching time was 6178 s.
	* Dependency graph time was 0 s.
	* Tarjan algorithm time was 0 s.
	* Loop creation time was 59 s.
	*********/
}


