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
#define __MAX_DATA_NUM 900


int main ( int argc , char** argv ) ;

int main ( int argc , char** argv ) {

	/*自身のランクを保持する変数*/
	int myrank;
	/*ノード数を保持する変数*/
	int nodenum;
	/*MPIのステータスを保持する変数*/
	MPI_Status recv_status;
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
	double st, en;

	/*MPI 初期化*/
	MPI_Init(&argc,&argv);
	/*MPI ランクを取得*/
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	/*クラスタの台数取得*/
	MPI_Comm_size(MPI_COMM_WORLD,&nodenum);


	/*MPIの計算部分指定*/
	calcindex = (859-43)/nodenum;
	mycalc = 43 + (calcindex * myrank) + calcindex - 1;
	if((859-43) % nodenum != 0 && myrank == nodenum - 1) mycalc += (859-43) % nodenum;
	if(calcindex == 0) {
		printf("ノード数が多すぎ今のところ対応していません\n");
		return -1;
	}
	sourcebuf = calcindex * myrank + 43;

	/*membrane_V__nのtemp*/
	double* membrane_V__n_temp;

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
	int n;
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
	double* __flag2__n;
	double* __flag24__n;
	double* __flag26__n;
	double* __flag46__n;
	double* __flag53__n;
	double* __flag72__n;
	double* __flag79__n;
	double* __flag96__n;
	double* __flag98__n;
	double* __flag100__n;
	double* __flag105__n;
	double* __flag118__n;
	double* __flag121__n;
	double* __flag122__n;
	int __i;

	/*membrane_V__nのtempの確保*/
	membrane_V__n_temp = malloc (  ( sizeof( double ) * __MAX_DATA_NUM)  );

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
	__flag2__n = malloc (  ( sizeof( double ) * 858-43+1 )  );
	__flag24__n = malloc (  ( sizeof( double ) * 41-13+1 )  );
	__flag26__n = malloc (  ( sizeof( double ) * 67-49+1 )  );
	__flag46__n = malloc (  ( sizeof( double ) * 317-312+1 )  );
	__flag53__n = malloc (  ( sizeof( double ) * 379-370+1 )  );
	__flag72__n = malloc (  ( sizeof( double ) * 529-520+1 )  );
	__flag79__n = malloc (  ( sizeof( double ) * 587-582+1 )  );
	__flag96__n = malloc (  ( sizeof( double ) * 817-803+1 )  );
	__flag98__n = malloc (  ( sizeof( double ) * 849-831+1 )  );
	__flag100__n = malloc (  ( sizeof( double ) * 888-859+1 )  );
	__flag105__n = malloc (  ( sizeof( double ) * 858-43+1 )  );
	__flag118__n = malloc (  ( sizeof( double ) * 858-43+1 )  );
	__flag121__n = malloc (  ( sizeof( double ) * 858-43+1 )  );
	__flag122__n = malloc (  ( sizeof( double ) * 858-43+1 )  );

	/*Revision: insert the initial values and change value of diffusion constant to 0.1*/
	membrane_D = (double)0.1;
	membrane_R = (double)8314.0;
	membrane_T = (double)310;
	membrane_F = (double)96484.6;
	membrane_C = (double)1;
	membrane_stim_start = (double)10; //default = 100
	membrane_stim_end = (double)100000000;
	membrane_stim_period = (double)1000;
	membrane_stim_duration = (double)5;
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

	/* REVISION: assign the value "1" to material node points for all flags
	 * NOTE: insert the max value of each flags*/
	int flag2__nSize = 858-43+1;
	int flag24__nSize = 41-13+1;
	int flag26__nSize = 67-49+1;
	int flag46__nSize = 317-312+1;
	int flag53__nSize = 379-370+1;
	int flag72__nSize = 529-520+1;
	int flag79__nSize = 587-582+1;
	int flag96__nSize = 817-803+1;
	int flag98__nSize = 849-831+1;
	int flag100__nSize = 888-859+1;
	int flag105__nSize = 858-43+1;
	int flag118__nSize = 858-43+1;
	int flag121__nSize = 858-43+1;
	int flag122__nSize = 858-43+1;
	for (__i = 0; __i < flag2__nSize; __i++) {
		__flag2__n[__i] = 1;
	}
	for (__i = 0; __i < flag24__nSize; __i++) {
		__flag24__n[__i] = 1;
	}
	for (__i = 0; __i < flag26__nSize; __i++) {
		__flag26__n[__i] = 1;
	}
	for (__i = 0; __i < flag46__nSize; __i++) {
		__flag46__n[__i] = 1;
	}
	for (__i = 0; __i < flag53__nSize; __i++) {
		__flag53__n[__i] = 1;
	}
	for (__i = 0; __i < flag72__nSize; __i++) {
		__flag72__n[__i] = 1;
	}
	for (__i = 0; __i < flag79__nSize; __i++) {
		__flag79__n[__i] = 1;
	}
	for (__i = 0; __i < flag96__nSize; __i++) {
		__flag96__n[__i] = 1;
	}
	for (__i = 0; __i < flag98__nSize; __i++) {
		__flag98__n[__i] = 1;
	}
	for (__i = 0; __i < flag100__nSize; __i++) {
		__flag100__n[__i] = 1;
	}
	for (__i = 0; __i < flag105__nSize; __i++) {
		__flag105__n[__i] = 1;
	}
	for (__i = 0; __i < flag118__nSize; __i++) {
		__flag118__n[__i] = 1;
	}
	for (__i = 0; __i < flag121__nSize; __i++) {
		__flag121__n[__i] = 1;
	}
	for (__i = 0; __i < flag122__nSize; __i++) {
		__flag122__n[__i] = 1;
	}


	/*Revision*/
	__flag2__n[49-43] = 0;
	__flag2__n[50-43] = 0;
	__flag2__n[51-43] = 0;
	__flag2__n[52-43] = 0;
	__flag2__n[53-43] = 0;
	__flag2__n[54-43] = 0;
	__flag2__n[55-43] = 0;
	__flag2__n[56-43] = 0;
	__flag2__n[57-43] = 0;
	__flag2__n[58-43] = 0;
	__flag2__n[59-43] = 0;
	__flag2__n[60-43] = 0;
	__flag2__n[61-43] = 0;
	__flag2__n[62-43] = 0;
	__flag2__n[63-43] = 0;
	__flag2__n[64-43] = 0;
	__flag2__n[65-43] = 0;
	__flag2__n[66-43] = 0;
	__flag2__n[67-43] = 0;
	__flag2__n[68-43] = 0;
	__flag2__n[81-43] = 0;
	__flag2__n[82-43] = 0;
	__flag2__n[83-43] = 0;
	__flag2__n[84-43] = 0;
	__flag2__n[85-43] = 0;
	__flag2__n[86-43] = 0;
	__flag2__n[87-43] = 0;
	__flag2__n[88-43] = 0;
	__flag2__n[89-43] = 0;
	__flag2__n[90-43] = 0;
	__flag2__n[91-43] = 0;
	__flag2__n[92-43] = 0;
	__flag2__n[93-43] = 0;
	__flag2__n[94-43] = 0;
	__flag2__n[95-43] = 0;
	__flag2__n[96-43] = 0;
	__flag2__n[113-43] = 0;
	__flag2__n[114-43] = 0;
	__flag2__n[115-43] = 0;
	__flag2__n[116-43] = 0;
	__flag2__n[117-43] = 0;
	__flag2__n[118-43] = 0;
	__flag2__n[119-43] = 0;
	__flag2__n[120-43] = 0;
	__flag2__n[121-43] = 0;
	__flag2__n[122-43] = 0;
	__flag2__n[123-43] = 0;
	__flag2__n[124-43] = 0;
	__flag2__n[125-43] = 0;
	__flag2__n[144-43] = 0;
	__flag2__n[145-43] = 0;
	__flag2__n[146-43] = 0;
	__flag2__n[147-43] = 0;
	__flag2__n[148-43] = 0;
	__flag2__n[149-43] = 0;
	__flag2__n[150-43] = 0;
	__flag2__n[151-43] = 0;
	__flag2__n[152-43] = 0;
	__flag2__n[153-43] = 0;
	__flag2__n[154-43] = 0;
	__flag2__n[175-43] = 0;
	__flag2__n[176-43] = 0;
	__flag2__n[177-43] = 0;
	__flag2__n[178-43] = 0;
	__flag2__n[179-43] = 0;
	__flag2__n[180-43] = 0;
	__flag2__n[181-43] = 0;
	__flag2__n[182-43] = 0;
	__flag2__n[183-43] = 0;
	__flag2__n[206-43] = 0;
	__flag2__n[207-43] = 0;
	__flag2__n[208-43] = 0;
	__flag2__n[209-43] = 0;
	__flag2__n[210-43] = 0;
	__flag2__n[211-43] = 0;
	__flag2__n[212-43] = 0;
	__flag2__n[237-43] = 0;
	__flag2__n[238-43] = 0;
	__flag2__n[239-43] = 0;
	__flag2__n[240-43] = 0;
	__flag2__n[241-43] = 0;
	__flag2__n[242-43] = 0;
	__flag2__n[267-43] = 0;
	__flag2__n[268-43] = 0;
	__flag2__n[269-43] = 0;
	__flag2__n[270-43] = 0;
	__flag2__n[271-43] = 0;
	__flag2__n[284-43] = 0;
	__flag2__n[285-43] = 0;
	__flag2__n[298-43] = 0;
	__flag2__n[299-43] = 0;
	__flag2__n[300-43] = 0;
	__flag2__n[301-43] = 0;
	__flag2__n[312-43] = 0;
	__flag2__n[313-43] = 0;
	__flag2__n[314-43] = 0;
	__flag2__n[315-43] = 0;
	__flag2__n[316-43] = 0;
	__flag2__n[317-43] = 0;
	__flag2__n[328-43] = 0;
	__flag2__n[329-43] = 0;
	__flag2__n[330-43] = 0;
	__flag2__n[341-43] = 0;
	__flag2__n[342-43] = 0;
	__flag2__n[343-43] = 0;
	__flag2__n[344-43] = 0;
	__flag2__n[345-43] = 0;
	__flag2__n[346-43] = 0;
	__flag2__n[347-43] = 0;
	__flag2__n[348-43] = 0;
	__flag2__n[359-43] = 0;
	__flag2__n[360-43] = 0;
	__flag2__n[370-43] = 0;
	__flag2__n[371-43] = 0;
	__flag2__n[372-43] = 0;
	__flag2__n[373-43] = 0;
	__flag2__n[374-43] = 0;
	__flag2__n[375-43] = 0;
	__flag2__n[376-43] = 0;
	__flag2__n[377-43] = 0;
	__flag2__n[378-43] = 0;
	__flag2__n[379-43] = 0;
	__flag2__n[389-43] = 0;
	__flag2__n[390-43] = 0;
	__flag2__n[400-43] = 0;
	__flag2__n[401-43] = 0;
	__flag2__n[402-43] = 0;
	__flag2__n[403-43] = 0;
	__flag2__n[404-43] = 0;
	__flag2__n[405-43] = 0;
	__flag2__n[406-43] = 0;
	__flag2__n[407-43] = 0;
	__flag2__n[408-43] = 0;
	__flag2__n[409-43] = 0;
	__flag2__n[419-43] = 0;
	__flag2__n[420-43] = 0;
	__flag2__n[429-43] = 0;
	__flag2__n[430-43] = 0;
	__flag2__n[431-43] = 0;
	__flag2__n[432-43] = 0;
	__flag2__n[433-43] = 0;
	__flag2__n[434-43] = 0;
	__flag2__n[435-43] = 0;
	__flag2__n[436-43] = 0;
	__flag2__n[437-43] = 0;
	__flag2__n[438-43] = 0;
	__flag2__n[439-43] = 0;
	__flag2__n[440-43] = 0;
	__flag2__n[449-43] = 0;
	__flag2__n[450-43] = 0;
	__flag2__n[459-43] = 0;
	__flag2__n[460-43] = 0;
	__flag2__n[461-43] = 0;
	__flag2__n[462-43] = 0;
	__flag2__n[463-43] = 0;
	__flag2__n[464-43] = 0;
	__flag2__n[465-43] = 0;
	__flag2__n[466-43] = 0;
	__flag2__n[467-43] = 0;
	__flag2__n[468-43] = 0;
	__flag2__n[469-43] = 0;
	__flag2__n[470-43] = 0;
	__flag2__n[479-43] = 0;
	__flag2__n[480-43] = 0;
	__flag2__n[490-43] = 0;
	__flag2__n[491-43] = 0;
	__flag2__n[492-43] = 0;
	__flag2__n[493-43] = 0;
	__flag2__n[494-43] = 0;
	__flag2__n[495-43] = 0;
	__flag2__n[496-43] = 0;
	__flag2__n[497-43] = 0;
	__flag2__n[498-43] = 0;
	__flag2__n[499-43] = 0;
	__flag2__n[509-43] = 0;
	__flag2__n[510-43] = 0;
	__flag2__n[520-43] = 0;
	__flag2__n[521-43] = 0;
	__flag2__n[522-43] = 0;
	__flag2__n[523-43] = 0;
	__flag2__n[524-43] = 0;
	__flag2__n[525-43] = 0;
	__flag2__n[526-43] = 0;
	__flag2__n[527-43] = 0;
	__flag2__n[528-43] = 0;
	__flag2__n[529-43] = 0;
	__flag2__n[539-43] = 0;
	__flag2__n[540-43] = 0;
	__flag2__n[551-43] = 0;
	__flag2__n[552-43] = 0;
	__flag2__n[553-43] = 0;
	__flag2__n[554-43] = 0;
	__flag2__n[555-43] = 0;
	__flag2__n[556-43] = 0;
	__flag2__n[557-43] = 0;
	__flag2__n[558-43] = 0;
	__flag2__n[569-43] = 0;
	__flag2__n[570-43] = 0;
	__flag2__n[571-43] = 0;
	__flag2__n[582-43] = 0;
	__flag2__n[583-43] = 0;
	__flag2__n[584-43] = 0;
	__flag2__n[585-43] = 0;
	__flag2__n[586-43] = 0;
	__flag2__n[587-43] = 0;
	__flag2__n[598-43] = 0;
	__flag2__n[599-43] = 0;
	__flag2__n[600-43] = 0;
	__flag2__n[601-43] = 0;
	__flag2__n[614-43] = 0;
	__flag2__n[615-43] = 0;
	__flag2__n[628-43] = 0;
	__flag2__n[629-43] = 0;
	__flag2__n[630-43] = 0;
	__flag2__n[631-43] = 0;
	__flag2__n[632-43] = 0;
	__flag2__n[657-43] = 0;
	__flag2__n[658-43] = 0;
	__flag2__n[659-43] = 0;
	__flag2__n[660-43] = 0;
	__flag2__n[661-43] = 0;
	__flag2__n[662-43] = 0;
	__flag2__n[687-43] = 0;
	__flag2__n[688-43] = 0;
	__flag2__n[689-43] = 0;
	__flag2__n[690-43] = 0;
	__flag2__n[691-43] = 0;
	__flag2__n[692-43] = 0;
	__flag2__n[693-43] = 0;
	__flag2__n[716-43] = 0;
	__flag2__n[717-43] = 0;
	__flag2__n[718-43] = 0;
	__flag2__n[719-43] = 0;
	__flag2__n[720-43] = 0;
	__flag2__n[721-43] = 0;
	__flag2__n[722-43] = 0;
	__flag2__n[723-43] = 0;
	__flag2__n[724-43] = 0;
	__flag2__n[745-43] = 0;
	__flag2__n[746-43] = 0;
	__flag2__n[747-43] = 0;
	__flag2__n[748-43] = 0;
	__flag2__n[749-43] = 0;
	__flag2__n[750-43] = 0;
	__flag2__n[751-43] = 0;
	__flag2__n[752-43] = 0;
	__flag2__n[753-43] = 0;
	__flag2__n[754-43] = 0;
	__flag2__n[755-43] = 0;
	__flag2__n[774-43] = 0;
	__flag2__n[775-43] = 0;
	__flag2__n[776-43] = 0;
	__flag2__n[777-43] = 0;
	__flag2__n[778-43] = 0;
	__flag2__n[779-43] = 0;
	__flag2__n[780-43] = 0;
	__flag2__n[781-43] = 0;
	__flag2__n[782-43] = 0;
	__flag2__n[783-43] = 0;
	__flag2__n[784-43] = 0;
	__flag2__n[785-43] = 0;
	__flag2__n[786-43] = 0;
	__flag2__n[803-43] = 0;
	__flag2__n[804-43] = 0;
	__flag2__n[805-43] = 0;
	__flag2__n[806-43] = 0;
	__flag2__n[807-43] = 0;
	__flag2__n[808-43] = 0;
	__flag2__n[809-43] = 0;
	__flag2__n[810-43] = 0;
	__flag2__n[811-43] = 0;
	__flag2__n[812-43] = 0;
	__flag2__n[813-43] = 0;
	__flag2__n[814-43] = 0;
	__flag2__n[815-43] = 0;
	__flag2__n[816-43] = 0;
	__flag2__n[817-43] = 0;
	__flag2__n[818-43] = 0;
	__flag2__n[831-43] = 0;
	__flag2__n[832-43] = 0;
	__flag2__n[833-43] = 0;
	__flag2__n[834-43] = 0;
	__flag2__n[835-43] = 0;
	__flag2__n[836-43] = 0;
	__flag2__n[837-43] = 0;
	__flag2__n[838-43] = 0;
	__flag2__n[839-43] = 0;
	__flag2__n[840-43] = 0;
	__flag2__n[841-43] = 0;
	__flag2__n[842-43] = 0;
	__flag2__n[843-43] = 0;
	__flag2__n[844-43] = 0;
	__flag2__n[845-43] = 0;
	__flag2__n[846-43] = 0;
	__flag2__n[847-43] = 0;
	__flag2__n[848-43] = 0;
	__flag2__n[849-43] = 0;
	__flag2__n[850-43] = 0;
	__flag24__n[19-13] = 0;
	__flag24__n[20-13] = 0;
	__flag24__n[21-13] = 0;
	__flag24__n[22-13] = 0;
	__flag24__n[23-13] = 0;
	__flag24__n[24-13] = 0;
	__flag24__n[25-13] = 0;
	__flag24__n[26-13] = 0;
	__flag24__n[27-13] = 0;
	__flag24__n[28-13] = 0;
	__flag24__n[29-13] = 0;
	__flag24__n[30-13] = 0;
	__flag24__n[31-13] = 0;
	__flag24__n[32-13] = 0;
	__flag24__n[33-13] = 0;
	__flag24__n[34-13] = 0;
	__flag24__n[35-13] = 0;
	__flag24__n[36-13] = 0;
	__flag24__n[37-13] = 0;
	__flag24__n[38-13] = 0;
	__flag26__n[51-49] = 0;
	__flag26__n[52-49] = 0;
	__flag26__n[53-49] = 0;
	__flag26__n[54-49] = 0;
	__flag26__n[55-49] = 0;
	__flag26__n[56-49] = 0;
	__flag26__n[57-49] = 0;
	__flag26__n[58-49] = 0;
	__flag26__n[59-49] = 0;
	__flag26__n[60-49] = 0;
	__flag26__n[61-49] = 0;
	__flag26__n[62-49] = 0;
	__flag26__n[63-49] = 0;
	__flag26__n[64-49] = 0;
	__flag26__n[65-49] = 0;
	__flag26__n[66-49] = 0;
	__flag46__n[314-312] = 0;
	__flag46__n[315-312] = 0;
	__flag53__n[371-370] = 0;
	__flag53__n[372-370] = 0;
	__flag53__n[373-370] = 0;
	__flag53__n[374-370] = 0;
	__flag53__n[375-370] = 0;
	__flag53__n[376-370] = 0;
	__flag53__n[377-370] = 0;
	__flag53__n[378-370] = 0;
	__flag72__n[521-520] = 0;
	__flag72__n[522-520] = 0;
	__flag72__n[523-520] = 0;
	__flag72__n[524-520] = 0;
	__flag72__n[525-520] = 0;
	__flag72__n[526-520] = 0;
	__flag72__n[527-520] = 0;
	__flag72__n[528-520] = 0;
	__flag79__n[584-582] = 0;
	__flag79__n[585-582] = 0;
	__flag96__n[804-803] = 0;
	__flag96__n[805-803] = 0;
	__flag96__n[806-803] = 0;
	__flag96__n[807-803] = 0;
	__flag96__n[808-803] = 0;
	__flag96__n[809-803] = 0;
	__flag96__n[810-803] = 0;
	__flag96__n[811-803] = 0;
	__flag96__n[812-803] = 0;
	__flag96__n[813-803] = 0;
	__flag96__n[814-803] = 0;
	__flag96__n[815-803] = 0;
	__flag96__n[816-803] = 0;
	__flag98__n[833-831] = 0;
	__flag98__n[834-831] = 0;
	__flag98__n[835-831] = 0;
	__flag98__n[836-831] = 0;
	__flag98__n[837-831] = 0;
	__flag98__n[838-831] = 0;
	__flag98__n[839-831] = 0;
	__flag98__n[840-831] = 0;
	__flag98__n[841-831] = 0;
	__flag98__n[842-831] = 0;
	__flag98__n[843-831] = 0;
	__flag98__n[844-831] = 0;
	__flag98__n[845-831] = 0;
	__flag98__n[846-831] = 0;
	__flag98__n[847-831] = 0;
	__flag98__n[848-831] = 0;
	__flag100__n[861-859] = 0;
	__flag100__n[862-859] = 0;
	__flag100__n[863-859] = 0;
	__flag100__n[864-859] = 0;
	__flag100__n[865-859] = 0;
	__flag100__n[866-859] = 0;
	__flag100__n[867-859] = 0;
	__flag100__n[868-859] = 0;
	__flag100__n[869-859] = 0;
	__flag100__n[870-859] = 0;
	__flag100__n[871-859] = 0;
	__flag100__n[872-859] = 0;
	__flag100__n[873-859] = 0;
	__flag100__n[874-859] = 0;
	__flag100__n[875-859] = 0;
	__flag100__n[876-859] = 0;
	__flag100__n[877-859] = 0;
	__flag100__n[878-859] = 0;
	__flag100__n[879-859] = 0;
	__flag100__n[880-859] = 0;
	__flag105__n[49-43] = 0;
	__flag105__n[50-43] = 0;
	__flag105__n[51-43] = 0;
	__flag105__n[52-43] = 0;
	__flag105__n[53-43] = 0;
	__flag105__n[54-43] = 0;
	__flag105__n[55-43] = 0;
	__flag105__n[56-43] = 0;
	__flag105__n[57-43] = 0;
	__flag105__n[58-43] = 0;
	__flag105__n[59-43] = 0;
	__flag105__n[60-43] = 0;
	__flag105__n[61-43] = 0;
	__flag105__n[62-43] = 0;
	__flag105__n[63-43] = 0;
	__flag105__n[64-43] = 0;
	__flag105__n[65-43] = 0;
	__flag105__n[66-43] = 0;
	__flag105__n[67-43] = 0;
	__flag105__n[68-43] = 0;
	__flag105__n[81-43] = 0;
	__flag105__n[82-43] = 0;
	__flag105__n[83-43] = 0;
	__flag105__n[84-43] = 0;
	__flag105__n[85-43] = 0;
	__flag105__n[86-43] = 0;
	__flag105__n[87-43] = 0;
	__flag105__n[88-43] = 0;
	__flag105__n[89-43] = 0;
	__flag105__n[90-43] = 0;
	__flag105__n[91-43] = 0;
	__flag105__n[92-43] = 0;
	__flag105__n[93-43] = 0;
	__flag105__n[94-43] = 0;
	__flag105__n[95-43] = 0;
	__flag105__n[96-43] = 0;
	__flag105__n[113-43] = 0;
	__flag105__n[114-43] = 0;
	__flag105__n[115-43] = 0;
	__flag105__n[116-43] = 0;
	__flag105__n[117-43] = 0;
	__flag105__n[118-43] = 0;
	__flag105__n[119-43] = 0;
	__flag105__n[120-43] = 0;
	__flag105__n[121-43] = 0;
	__flag105__n[122-43] = 0;
	__flag105__n[123-43] = 0;
	__flag105__n[124-43] = 0;
	__flag105__n[125-43] = 0;
	__flag105__n[144-43] = 0;
	__flag105__n[145-43] = 0;
	__flag105__n[146-43] = 0;
	__flag105__n[147-43] = 0;
	__flag105__n[148-43] = 0;
	__flag105__n[149-43] = 0;
	__flag105__n[150-43] = 0;
	__flag105__n[151-43] = 0;
	__flag105__n[152-43] = 0;
	__flag105__n[153-43] = 0;
	__flag105__n[154-43] = 0;
	__flag105__n[175-43] = 0;
	__flag105__n[176-43] = 0;
	__flag105__n[177-43] = 0;
	__flag105__n[178-43] = 0;
	__flag105__n[179-43] = 0;
	__flag105__n[180-43] = 0;
	__flag105__n[181-43] = 0;
	__flag105__n[182-43] = 0;
	__flag105__n[183-43] = 0;
	__flag105__n[206-43] = 0;
	__flag105__n[207-43] = 0;
	__flag105__n[208-43] = 0;
	__flag105__n[209-43] = 0;
	__flag105__n[210-43] = 0;
	__flag105__n[211-43] = 0;
	__flag105__n[212-43] = 0;
	__flag105__n[237-43] = 0;
	__flag105__n[238-43] = 0;
	__flag105__n[239-43] = 0;
	__flag105__n[240-43] = 0;
	__flag105__n[241-43] = 0;
	__flag105__n[242-43] = 0;
	__flag105__n[267-43] = 0;
	__flag105__n[268-43] = 0;
	__flag105__n[269-43] = 0;
	__flag105__n[270-43] = 0;
	__flag105__n[271-43] = 0;
	__flag105__n[284-43] = 0;
	__flag105__n[285-43] = 0;
	__flag105__n[298-43] = 0;
	__flag105__n[299-43] = 0;
	__flag105__n[300-43] = 0;
	__flag105__n[301-43] = 0;
	__flag105__n[312-43] = 0;
	__flag105__n[313-43] = 0;
	__flag105__n[314-43] = 0;
	__flag105__n[315-43] = 0;
	__flag105__n[316-43] = 0;
	__flag105__n[317-43] = 0;
	__flag105__n[328-43] = 0;
	__flag105__n[329-43] = 0;
	__flag105__n[330-43] = 0;
	__flag105__n[341-43] = 0;
	__flag105__n[342-43] = 0;
	__flag105__n[343-43] = 0;
	__flag105__n[344-43] = 0;
	__flag105__n[345-43] = 0;
	__flag105__n[346-43] = 0;
	__flag105__n[347-43] = 0;
	__flag105__n[348-43] = 0;
	__flag105__n[359-43] = 0;
	__flag105__n[360-43] = 0;
	__flag105__n[370-43] = 0;
	__flag105__n[371-43] = 0;
	__flag105__n[372-43] = 0;
	__flag105__n[373-43] = 0;
	__flag105__n[374-43] = 0;
	__flag105__n[375-43] = 0;
	__flag105__n[376-43] = 0;
	__flag105__n[377-43] = 0;
	__flag105__n[378-43] = 0;
	__flag105__n[379-43] = 0;
	__flag105__n[389-43] = 0;
	__flag105__n[390-43] = 0;
	__flag105__n[400-43] = 0;
	__flag105__n[401-43] = 0;
	__flag105__n[402-43] = 0;
	__flag105__n[403-43] = 0;
	__flag105__n[404-43] = 0;
	__flag105__n[405-43] = 0;
	__flag105__n[406-43] = 0;
	__flag105__n[407-43] = 0;
	__flag105__n[408-43] = 0;
	__flag105__n[409-43] = 0;
	__flag105__n[419-43] = 0;
	__flag105__n[420-43] = 0;
	__flag105__n[429-43] = 0;
	__flag105__n[430-43] = 0;
	__flag105__n[431-43] = 0;
	__flag105__n[432-43] = 0;
	__flag105__n[433-43] = 0;
	__flag105__n[434-43] = 0;
	__flag105__n[435-43] = 0;
	__flag105__n[436-43] = 0;
	__flag105__n[437-43] = 0;
	__flag105__n[438-43] = 0;
	__flag105__n[439-43] = 0;
	__flag105__n[440-43] = 0;
	__flag105__n[449-43] = 0;
	__flag105__n[450-43] = 0;
	__flag105__n[459-43] = 0;
	__flag105__n[460-43] = 0;
	__flag105__n[461-43] = 0;
	__flag105__n[462-43] = 0;
	__flag105__n[463-43] = 0;
	__flag105__n[464-43] = 0;
	__flag105__n[465-43] = 0;
	__flag105__n[466-43] = 0;
	__flag105__n[467-43] = 0;
	__flag105__n[468-43] = 0;
	__flag105__n[469-43] = 0;
	__flag105__n[470-43] = 0;
	__flag105__n[479-43] = 0;
	__flag105__n[480-43] = 0;
	__flag105__n[490-43] = 0;
	__flag105__n[491-43] = 0;
	__flag105__n[492-43] = 0;
	__flag105__n[493-43] = 0;
	__flag105__n[494-43] = 0;
	__flag105__n[495-43] = 0;
	__flag105__n[496-43] = 0;
	__flag105__n[497-43] = 0;
	__flag105__n[498-43] = 0;
	__flag105__n[499-43] = 0;
	__flag105__n[509-43] = 0;
	__flag105__n[510-43] = 0;
	__flag105__n[520-43] = 0;
	__flag105__n[521-43] = 0;
	__flag105__n[522-43] = 0;
	__flag105__n[523-43] = 0;
	__flag105__n[524-43] = 0;
	__flag105__n[525-43] = 0;
	__flag105__n[526-43] = 0;
	__flag105__n[527-43] = 0;
	__flag105__n[528-43] = 0;
	__flag105__n[529-43] = 0;
	__flag105__n[539-43] = 0;
	__flag105__n[540-43] = 0;
	__flag105__n[551-43] = 0;
	__flag105__n[552-43] = 0;
	__flag105__n[553-43] = 0;
	__flag105__n[554-43] = 0;
	__flag105__n[555-43] = 0;
	__flag105__n[556-43] = 0;
	__flag105__n[557-43] = 0;
	__flag105__n[558-43] = 0;
	__flag105__n[569-43] = 0;
	__flag105__n[570-43] = 0;
	__flag105__n[571-43] = 0;
	__flag105__n[582-43] = 0;
	__flag105__n[583-43] = 0;
	__flag105__n[584-43] = 0;
	__flag105__n[585-43] = 0;
	__flag105__n[586-43] = 0;
	__flag105__n[587-43] = 0;
	__flag105__n[598-43] = 0;
	__flag105__n[599-43] = 0;
	__flag105__n[600-43] = 0;
	__flag105__n[601-43] = 0;
	__flag105__n[614-43] = 0;
	__flag105__n[615-43] = 0;
	__flag105__n[628-43] = 0;
	__flag105__n[629-43] = 0;
	__flag105__n[630-43] = 0;
	__flag105__n[631-43] = 0;
	__flag105__n[632-43] = 0;
	__flag105__n[657-43] = 0;
	__flag105__n[658-43] = 0;
	__flag105__n[659-43] = 0;
	__flag105__n[660-43] = 0;
	__flag105__n[661-43] = 0;
	__flag105__n[662-43] = 0;
	__flag105__n[687-43] = 0;
	__flag105__n[688-43] = 0;
	__flag105__n[689-43] = 0;
	__flag105__n[690-43] = 0;
	__flag105__n[691-43] = 0;
	__flag105__n[692-43] = 0;
	__flag105__n[693-43] = 0;
	__flag105__n[716-43] = 0;
	__flag105__n[717-43] = 0;
	__flag105__n[718-43] = 0;
	__flag105__n[719-43] = 0;
	__flag105__n[720-43] = 0;
	__flag105__n[721-43] = 0;
	__flag105__n[722-43] = 0;
	__flag105__n[723-43] = 0;
	__flag105__n[724-43] = 0;
	__flag105__n[745-43] = 0;
	__flag105__n[746-43] = 0;
	__flag105__n[747-43] = 0;
	__flag105__n[748-43] = 0;
	__flag105__n[749-43] = 0;
	__flag105__n[750-43] = 0;
	__flag105__n[751-43] = 0;
	__flag105__n[752-43] = 0;
	__flag105__n[753-43] = 0;
	__flag105__n[754-43] = 0;
	__flag105__n[755-43] = 0;
	__flag105__n[774-43] = 0;
	__flag105__n[775-43] = 0;
	__flag105__n[776-43] = 0;
	__flag105__n[777-43] = 0;
	__flag105__n[778-43] = 0;
	__flag105__n[779-43] = 0;
	__flag105__n[780-43] = 0;
	__flag105__n[781-43] = 0;
	__flag105__n[782-43] = 0;
	__flag105__n[783-43] = 0;
	__flag105__n[784-43] = 0;
	__flag105__n[785-43] = 0;
	__flag105__n[786-43] = 0;
	__flag105__n[803-43] = 0;
	__flag105__n[804-43] = 0;
	__flag105__n[805-43] = 0;
	__flag105__n[806-43] = 0;
	__flag105__n[807-43] = 0;
	__flag105__n[808-43] = 0;
	__flag105__n[809-43] = 0;
	__flag105__n[810-43] = 0;
	__flag105__n[811-43] = 0;
	__flag105__n[812-43] = 0;
	__flag105__n[813-43] = 0;
	__flag105__n[814-43] = 0;
	__flag105__n[815-43] = 0;
	__flag105__n[816-43] = 0;
	__flag105__n[817-43] = 0;
	__flag105__n[818-43] = 0;
	__flag105__n[831-43] = 0;
	__flag105__n[832-43] = 0;
	__flag105__n[833-43] = 0;
	__flag105__n[834-43] = 0;
	__flag105__n[835-43] = 0;
	__flag105__n[836-43] = 0;
	__flag105__n[837-43] = 0;
	__flag105__n[838-43] = 0;
	__flag105__n[839-43] = 0;
	__flag105__n[840-43] = 0;
	__flag105__n[841-43] = 0;
	__flag105__n[842-43] = 0;
	__flag105__n[843-43] = 0;
	__flag105__n[844-43] = 0;
	__flag105__n[845-43] = 0;
	__flag105__n[846-43] = 0;
	__flag105__n[847-43] = 0;
	__flag105__n[848-43] = 0;
	__flag105__n[849-43] = 0;
	__flag105__n[850-43] = 0;
	__flag118__n[49-43] = 0;
	__flag118__n[50-43] = 0;
	__flag118__n[51-43] = 0;
	__flag118__n[52-43] = 0;
	__flag118__n[53-43] = 0;
	__flag118__n[54-43] = 0;
	__flag118__n[55-43] = 0;
	__flag118__n[56-43] = 0;
	__flag118__n[57-43] = 0;
	__flag118__n[58-43] = 0;
	__flag118__n[59-43] = 0;
	__flag118__n[60-43] = 0;
	__flag118__n[61-43] = 0;
	__flag118__n[62-43] = 0;
	__flag118__n[63-43] = 0;
	__flag118__n[64-43] = 0;
	__flag118__n[65-43] = 0;
	__flag118__n[66-43] = 0;
	__flag118__n[67-43] = 0;
	__flag118__n[68-43] = 0;
	__flag118__n[81-43] = 0;
	__flag118__n[82-43] = 0;
	__flag118__n[83-43] = 0;
	__flag118__n[84-43] = 0;
	__flag118__n[85-43] = 0;
	__flag118__n[86-43] = 0;
	__flag118__n[87-43] = 0;
	__flag118__n[88-43] = 0;
	__flag118__n[89-43] = 0;
	__flag118__n[90-43] = 0;
	__flag118__n[91-43] = 0;
	__flag118__n[92-43] = 0;
	__flag118__n[93-43] = 0;
	__flag118__n[94-43] = 0;
	__flag118__n[95-43] = 0;
	__flag118__n[96-43] = 0;
	__flag118__n[113-43] = 0;
	__flag118__n[114-43] = 0;
	__flag118__n[115-43] = 0;
	__flag118__n[116-43] = 0;
	__flag118__n[117-43] = 0;
	__flag118__n[118-43] = 0;
	__flag118__n[119-43] = 0;
	__flag118__n[120-43] = 0;
	__flag118__n[121-43] = 0;
	__flag118__n[122-43] = 0;
	__flag118__n[123-43] = 0;
	__flag118__n[124-43] = 0;
	__flag118__n[125-43] = 0;
	__flag118__n[144-43] = 0;
	__flag118__n[145-43] = 0;
	__flag118__n[146-43] = 0;
	__flag118__n[147-43] = 0;
	__flag118__n[148-43] = 0;
	__flag118__n[149-43] = 0;
	__flag118__n[150-43] = 0;
	__flag118__n[151-43] = 0;
	__flag118__n[152-43] = 0;
	__flag118__n[153-43] = 0;
	__flag118__n[154-43] = 0;
	__flag118__n[175-43] = 0;
	__flag118__n[176-43] = 0;
	__flag118__n[177-43] = 0;
	__flag118__n[178-43] = 0;
	__flag118__n[179-43] = 0;
	__flag118__n[180-43] = 0;
	__flag118__n[181-43] = 0;
	__flag118__n[182-43] = 0;
	__flag118__n[183-43] = 0;
	__flag118__n[206-43] = 0;
	__flag118__n[207-43] = 0;
	__flag118__n[208-43] = 0;
	__flag118__n[209-43] = 0;
	__flag118__n[210-43] = 0;
	__flag118__n[211-43] = 0;
	__flag118__n[212-43] = 0;
	__flag118__n[237-43] = 0;
	__flag118__n[238-43] = 0;
	__flag118__n[239-43] = 0;
	__flag118__n[240-43] = 0;
	__flag118__n[241-43] = 0;
	__flag118__n[242-43] = 0;
	__flag118__n[267-43] = 0;
	__flag118__n[268-43] = 0;
	__flag118__n[269-43] = 0;
	__flag118__n[270-43] = 0;
	__flag118__n[271-43] = 0;
	__flag118__n[284-43] = 0;
	__flag118__n[285-43] = 0;
	__flag118__n[298-43] = 0;
	__flag118__n[299-43] = 0;
	__flag118__n[300-43] = 0;
	__flag118__n[301-43] = 0;
	__flag118__n[312-43] = 0;
	__flag118__n[313-43] = 0;
	__flag118__n[314-43] = 0;
	__flag118__n[315-43] = 0;
	__flag118__n[316-43] = 0;
	__flag118__n[317-43] = 0;
	__flag118__n[328-43] = 0;
	__flag118__n[329-43] = 0;
	__flag118__n[330-43] = 0;
	__flag118__n[341-43] = 0;
	__flag118__n[342-43] = 0;
	__flag118__n[343-43] = 0;
	__flag118__n[344-43] = 0;
	__flag118__n[345-43] = 0;
	__flag118__n[346-43] = 0;
	__flag118__n[347-43] = 0;
	__flag118__n[348-43] = 0;
	__flag118__n[359-43] = 0;
	__flag118__n[360-43] = 0;
	__flag118__n[370-43] = 0;
	__flag118__n[371-43] = 0;
	__flag118__n[372-43] = 0;
	__flag118__n[373-43] = 0;
	__flag118__n[374-43] = 0;
	__flag118__n[375-43] = 0;
	__flag118__n[376-43] = 0;
	__flag118__n[377-43] = 0;
	__flag118__n[378-43] = 0;
	__flag118__n[379-43] = 0;
	__flag118__n[389-43] = 0;
	__flag118__n[390-43] = 0;
	__flag118__n[400-43] = 0;
	__flag118__n[401-43] = 0;
	__flag118__n[402-43] = 0;
	__flag118__n[403-43] = 0;
	__flag118__n[404-43] = 0;
	__flag118__n[405-43] = 0;
	__flag118__n[406-43] = 0;
	__flag118__n[407-43] = 0;
	__flag118__n[408-43] = 0;
	__flag118__n[409-43] = 0;
	__flag118__n[419-43] = 0;
	__flag118__n[420-43] = 0;
	__flag118__n[429-43] = 0;
	__flag118__n[430-43] = 0;
	__flag118__n[431-43] = 0;
	__flag118__n[432-43] = 0;
	__flag118__n[433-43] = 0;
	__flag118__n[434-43] = 0;
	__flag118__n[435-43] = 0;
	__flag118__n[436-43] = 0;
	__flag118__n[437-43] = 0;
	__flag118__n[438-43] = 0;
	__flag118__n[439-43] = 0;
	__flag118__n[440-43] = 0;
	__flag118__n[449-43] = 0;
	__flag118__n[450-43] = 0;
	__flag118__n[459-43] = 0;
	__flag118__n[460-43] = 0;
	__flag118__n[461-43] = 0;
	__flag118__n[462-43] = 0;
	__flag118__n[463-43] = 0;
	__flag118__n[464-43] = 0;
	__flag118__n[465-43] = 0;
	__flag118__n[466-43] = 0;
	__flag118__n[467-43] = 0;
	__flag118__n[468-43] = 0;
	__flag118__n[469-43] = 0;
	__flag118__n[470-43] = 0;
	__flag118__n[479-43] = 0;
	__flag118__n[480-43] = 0;
	__flag118__n[490-43] = 0;
	__flag118__n[491-43] = 0;
	__flag118__n[492-43] = 0;
	__flag118__n[493-43] = 0;
	__flag118__n[494-43] = 0;
	__flag118__n[495-43] = 0;
	__flag118__n[496-43] = 0;
	__flag118__n[497-43] = 0;
	__flag118__n[498-43] = 0;
	__flag118__n[499-43] = 0;
	__flag118__n[509-43] = 0;
	__flag118__n[510-43] = 0;
	__flag118__n[520-43] = 0;
	__flag118__n[521-43] = 0;
	__flag118__n[522-43] = 0;
	__flag118__n[523-43] = 0;
	__flag118__n[524-43] = 0;
	__flag118__n[525-43] = 0;
	__flag118__n[526-43] = 0;
	__flag118__n[527-43] = 0;
	__flag118__n[528-43] = 0;
	__flag118__n[529-43] = 0;
	__flag118__n[539-43] = 0;
	__flag118__n[540-43] = 0;
	__flag118__n[551-43] = 0;
	__flag118__n[552-43] = 0;
	__flag118__n[553-43] = 0;
	__flag118__n[554-43] = 0;
	__flag118__n[555-43] = 0;
	__flag118__n[556-43] = 0;
	__flag118__n[557-43] = 0;
	__flag118__n[558-43] = 0;
	__flag118__n[569-43] = 0;
	__flag118__n[570-43] = 0;
	__flag118__n[571-43] = 0;
	__flag118__n[582-43] = 0;
	__flag118__n[583-43] = 0;
	__flag118__n[584-43] = 0;
	__flag118__n[585-43] = 0;
	__flag118__n[586-43] = 0;
	__flag118__n[587-43] = 0;
	__flag118__n[598-43] = 0;
	__flag118__n[599-43] = 0;
	__flag118__n[600-43] = 0;
	__flag118__n[601-43] = 0;
	__flag118__n[614-43] = 0;
	__flag118__n[615-43] = 0;
	__flag118__n[628-43] = 0;
	__flag118__n[629-43] = 0;
	__flag118__n[630-43] = 0;
	__flag118__n[631-43] = 0;
	__flag118__n[632-43] = 0;
	__flag118__n[657-43] = 0;
	__flag118__n[658-43] = 0;
	__flag118__n[659-43] = 0;
	__flag118__n[660-43] = 0;
	__flag118__n[661-43] = 0;
	__flag118__n[662-43] = 0;
	__flag118__n[687-43] = 0;
	__flag118__n[688-43] = 0;
	__flag118__n[689-43] = 0;
	__flag118__n[690-43] = 0;
	__flag118__n[691-43] = 0;
	__flag118__n[692-43] = 0;
	__flag118__n[693-43] = 0;
	__flag118__n[716-43] = 0;
	__flag118__n[717-43] = 0;
	__flag118__n[718-43] = 0;
	__flag118__n[719-43] = 0;
	__flag118__n[720-43] = 0;
	__flag118__n[721-43] = 0;
	__flag118__n[722-43] = 0;
	__flag118__n[723-43] = 0;
	__flag118__n[724-43] = 0;
	__flag118__n[745-43] = 0;
	__flag118__n[746-43] = 0;
	__flag118__n[747-43] = 0;
	__flag118__n[748-43] = 0;
	__flag118__n[749-43] = 0;
	__flag118__n[750-43] = 0;
	__flag118__n[751-43] = 0;
	__flag118__n[752-43] = 0;
	__flag118__n[753-43] = 0;
	__flag118__n[754-43] = 0;
	__flag118__n[755-43] = 0;
	__flag118__n[774-43] = 0;
	__flag118__n[775-43] = 0;
	__flag118__n[776-43] = 0;
	__flag118__n[777-43] = 0;
	__flag118__n[778-43] = 0;
	__flag118__n[779-43] = 0;
	__flag118__n[780-43] = 0;
	__flag118__n[781-43] = 0;
	__flag118__n[782-43] = 0;
	__flag118__n[783-43] = 0;
	__flag118__n[784-43] = 0;
	__flag118__n[785-43] = 0;
	__flag118__n[786-43] = 0;
	__flag118__n[803-43] = 0;
	__flag118__n[804-43] = 0;
	__flag118__n[805-43] = 0;
	__flag118__n[806-43] = 0;
	__flag118__n[807-43] = 0;
	__flag118__n[808-43] = 0;
	__flag118__n[809-43] = 0;
	__flag118__n[810-43] = 0;
	__flag118__n[811-43] = 0;
	__flag118__n[812-43] = 0;
	__flag118__n[813-43] = 0;
	__flag118__n[814-43] = 0;
	__flag118__n[815-43] = 0;
	__flag118__n[816-43] = 0;
	__flag118__n[817-43] = 0;
	__flag118__n[818-43] = 0;
	__flag118__n[831-43] = 0;
	__flag118__n[832-43] = 0;
	__flag118__n[833-43] = 0;
	__flag118__n[834-43] = 0;
	__flag118__n[835-43] = 0;
	__flag118__n[836-43] = 0;
	__flag118__n[837-43] = 0;
	__flag118__n[838-43] = 0;
	__flag118__n[839-43] = 0;
	__flag118__n[840-43] = 0;
	__flag118__n[841-43] = 0;
	__flag118__n[842-43] = 0;
	__flag118__n[843-43] = 0;
	__flag118__n[844-43] = 0;
	__flag118__n[845-43] = 0;
	__flag118__n[846-43] = 0;
	__flag118__n[847-43] = 0;
	__flag118__n[848-43] = 0;
	__flag118__n[849-43] = 0;
	__flag118__n[850-43] = 0;
	__flag121__n[49-43] = 0;
	__flag121__n[50-43] = 0;
	__flag121__n[51-43] = 0;
	__flag121__n[52-43] = 0;
	__flag121__n[53-43] = 0;
	__flag121__n[54-43] = 0;
	__flag121__n[55-43] = 0;
	__flag121__n[56-43] = 0;
	__flag121__n[57-43] = 0;
	__flag121__n[58-43] = 0;
	__flag121__n[59-43] = 0;
	__flag121__n[60-43] = 0;
	__flag121__n[61-43] = 0;
	__flag121__n[62-43] = 0;
	__flag121__n[63-43] = 0;
	__flag121__n[64-43] = 0;
	__flag121__n[65-43] = 0;
	__flag121__n[66-43] = 0;
	__flag121__n[67-43] = 0;
	__flag121__n[68-43] = 0;
	__flag121__n[81-43] = 0;
	__flag121__n[82-43] = 0;
	__flag121__n[83-43] = 0;
	__flag121__n[84-43] = 0;
	__flag121__n[85-43] = 0;
	__flag121__n[86-43] = 0;
	__flag121__n[87-43] = 0;
	__flag121__n[88-43] = 0;
	__flag121__n[89-43] = 0;
	__flag121__n[90-43] = 0;
	__flag121__n[91-43] = 0;
	__flag121__n[92-43] = 0;
	__flag121__n[93-43] = 0;
	__flag121__n[94-43] = 0;
	__flag121__n[95-43] = 0;
	__flag121__n[96-43] = 0;
	__flag121__n[113-43] = 0;
	__flag121__n[114-43] = 0;
	__flag121__n[115-43] = 0;
	__flag121__n[116-43] = 0;
	__flag121__n[117-43] = 0;
	__flag121__n[118-43] = 0;
	__flag121__n[119-43] = 0;
	__flag121__n[120-43] = 0;
	__flag121__n[121-43] = 0;
	__flag121__n[122-43] = 0;
	__flag121__n[123-43] = 0;
	__flag121__n[124-43] = 0;
	__flag121__n[125-43] = 0;
	__flag121__n[144-43] = 0;
	__flag121__n[145-43] = 0;
	__flag121__n[146-43] = 0;
	__flag121__n[147-43] = 0;
	__flag121__n[148-43] = 0;
	__flag121__n[149-43] = 0;
	__flag121__n[150-43] = 0;
	__flag121__n[151-43] = 0;
	__flag121__n[152-43] = 0;
	__flag121__n[153-43] = 0;
	__flag121__n[154-43] = 0;
	__flag121__n[175-43] = 0;
	__flag121__n[176-43] = 0;
	__flag121__n[177-43] = 0;
	__flag121__n[178-43] = 0;
	__flag121__n[179-43] = 0;
	__flag121__n[180-43] = 0;
	__flag121__n[181-43] = 0;
	__flag121__n[182-43] = 0;
	__flag121__n[183-43] = 0;
	__flag121__n[206-43] = 0;
	__flag121__n[207-43] = 0;
	__flag121__n[208-43] = 0;
	__flag121__n[209-43] = 0;
	__flag121__n[210-43] = 0;
	__flag121__n[211-43] = 0;
	__flag121__n[212-43] = 0;
	__flag121__n[237-43] = 0;
	__flag121__n[238-43] = 0;
	__flag121__n[239-43] = 0;
	__flag121__n[240-43] = 0;
	__flag121__n[241-43] = 0;
	__flag121__n[242-43] = 0;
	__flag121__n[267-43] = 0;
	__flag121__n[268-43] = 0;
	__flag121__n[269-43] = 0;
	__flag121__n[270-43] = 0;
	__flag121__n[271-43] = 0;
	__flag121__n[284-43] = 0;
	__flag121__n[285-43] = 0;
	__flag121__n[298-43] = 0;
	__flag121__n[299-43] = 0;
	__flag121__n[300-43] = 0;
	__flag121__n[301-43] = 0;
	__flag121__n[312-43] = 0;
	__flag121__n[313-43] = 0;
	__flag121__n[314-43] = 0;
	__flag121__n[315-43] = 0;
	__flag121__n[316-43] = 0;
	__flag121__n[317-43] = 0;
	__flag121__n[328-43] = 0;
	__flag121__n[329-43] = 0;
	__flag121__n[330-43] = 0;
	__flag121__n[341-43] = 0;
	__flag121__n[342-43] = 0;
	__flag121__n[343-43] = 0;
	__flag121__n[344-43] = 0;
	__flag121__n[345-43] = 0;
	__flag121__n[346-43] = 0;
	__flag121__n[347-43] = 0;
	__flag121__n[348-43] = 0;
	__flag121__n[359-43] = 0;
	__flag121__n[360-43] = 0;
	__flag121__n[370-43] = 0;
	__flag121__n[371-43] = 0;
	__flag121__n[372-43] = 0;
	__flag121__n[373-43] = 0;
	__flag121__n[374-43] = 0;
	__flag121__n[375-43] = 0;
	__flag121__n[376-43] = 0;
	__flag121__n[377-43] = 0;
	__flag121__n[378-43] = 0;
	__flag121__n[379-43] = 0;
	__flag121__n[389-43] = 0;
	__flag121__n[390-43] = 0;
	__flag121__n[400-43] = 0;
	__flag121__n[401-43] = 0;
	__flag121__n[402-43] = 0;
	__flag121__n[403-43] = 0;
	__flag121__n[404-43] = 0;
	__flag121__n[405-43] = 0;
	__flag121__n[406-43] = 0;
	__flag121__n[407-43] = 0;
	__flag121__n[408-43] = 0;
	__flag121__n[409-43] = 0;
	__flag121__n[419-43] = 0;
	__flag121__n[420-43] = 0;
	__flag121__n[429-43] = 0;
	__flag121__n[430-43] = 0;
	__flag121__n[431-43] = 0;
	__flag121__n[432-43] = 0;
	__flag121__n[433-43] = 0;
	__flag121__n[434-43] = 0;
	__flag121__n[435-43] = 0;
	__flag121__n[436-43] = 0;
	__flag121__n[437-43] = 0;
	__flag121__n[438-43] = 0;
	__flag121__n[439-43] = 0;
	__flag121__n[440-43] = 0;
	__flag121__n[449-43] = 0;
	__flag121__n[450-43] = 0;
	__flag121__n[459-43] = 0;
	__flag121__n[460-43] = 0;
	__flag121__n[461-43] = 0;
	__flag121__n[462-43] = 0;
	__flag121__n[463-43] = 0;
	__flag121__n[464-43] = 0;
	__flag121__n[465-43] = 0;
	__flag121__n[466-43] = 0;
	__flag121__n[467-43] = 0;
	__flag121__n[468-43] = 0;
	__flag121__n[469-43] = 0;
	__flag121__n[470-43] = 0;
	__flag121__n[479-43] = 0;
	__flag121__n[480-43] = 0;
	__flag121__n[490-43] = 0;
	__flag121__n[491-43] = 0;
	__flag121__n[492-43] = 0;
	__flag121__n[493-43] = 0;
	__flag121__n[494-43] = 0;
	__flag121__n[495-43] = 0;
	__flag121__n[496-43] = 0;
	__flag121__n[497-43] = 0;
	__flag121__n[498-43] = 0;
	__flag121__n[499-43] = 0;
	__flag121__n[509-43] = 0;
	__flag121__n[510-43] = 0;
	__flag121__n[520-43] = 0;
	__flag121__n[521-43] = 0;
	__flag121__n[522-43] = 0;
	__flag121__n[523-43] = 0;
	__flag121__n[524-43] = 0;
	__flag121__n[525-43] = 0;
	__flag121__n[526-43] = 0;
	__flag121__n[527-43] = 0;
	__flag121__n[528-43] = 0;
	__flag121__n[529-43] = 0;
	__flag121__n[539-43] = 0;
	__flag121__n[540-43] = 0;
	__flag121__n[551-43] = 0;
	__flag121__n[552-43] = 0;
	__flag121__n[553-43] = 0;
	__flag121__n[554-43] = 0;
	__flag121__n[555-43] = 0;
	__flag121__n[556-43] = 0;
	__flag121__n[557-43] = 0;
	__flag121__n[558-43] = 0;
	__flag121__n[569-43] = 0;
	__flag121__n[570-43] = 0;
	__flag121__n[571-43] = 0;
	__flag121__n[582-43] = 0;
	__flag121__n[583-43] = 0;
	__flag121__n[584-43] = 0;
	__flag121__n[585-43] = 0;
	__flag121__n[586-43] = 0;
	__flag121__n[587-43] = 0;
	__flag121__n[598-43] = 0;
	__flag121__n[599-43] = 0;
	__flag121__n[600-43] = 0;
	__flag121__n[601-43] = 0;
	__flag121__n[614-43] = 0;
	__flag121__n[615-43] = 0;
	__flag121__n[628-43] = 0;
	__flag121__n[629-43] = 0;
	__flag121__n[630-43] = 0;
	__flag121__n[631-43] = 0;
	__flag121__n[632-43] = 0;
	__flag121__n[657-43] = 0;
	__flag121__n[658-43] = 0;
	__flag121__n[659-43] = 0;
	__flag121__n[660-43] = 0;
	__flag121__n[661-43] = 0;
	__flag121__n[662-43] = 0;
	__flag121__n[687-43] = 0;
	__flag121__n[688-43] = 0;
	__flag121__n[689-43] = 0;
	__flag121__n[690-43] = 0;
	__flag121__n[691-43] = 0;
	__flag121__n[692-43] = 0;
	__flag121__n[693-43] = 0;
	__flag121__n[716-43] = 0;
	__flag121__n[717-43] = 0;
	__flag121__n[718-43] = 0;
	__flag121__n[719-43] = 0;
	__flag121__n[720-43] = 0;
	__flag121__n[721-43] = 0;
	__flag121__n[722-43] = 0;
	__flag121__n[723-43] = 0;
	__flag121__n[724-43] = 0;
	__flag121__n[745-43] = 0;
	__flag121__n[746-43] = 0;
	__flag121__n[747-43] = 0;
	__flag121__n[748-43] = 0;
	__flag121__n[749-43] = 0;
	__flag121__n[750-43] = 0;
	__flag121__n[751-43] = 0;
	__flag121__n[752-43] = 0;
	__flag121__n[753-43] = 0;
	__flag121__n[754-43] = 0;
	__flag121__n[755-43] = 0;
	__flag121__n[774-43] = 0;
	__flag121__n[775-43] = 0;
	__flag121__n[776-43] = 0;
	__flag121__n[777-43] = 0;
	__flag121__n[778-43] = 0;
	__flag121__n[779-43] = 0;
	__flag121__n[780-43] = 0;
	__flag121__n[781-43] = 0;
	__flag121__n[782-43] = 0;
	__flag121__n[783-43] = 0;
	__flag121__n[784-43] = 0;
	__flag121__n[785-43] = 0;
	__flag121__n[786-43] = 0;
	__flag121__n[803-43] = 0;
	__flag121__n[804-43] = 0;
	__flag121__n[805-43] = 0;
	__flag121__n[806-43] = 0;
	__flag121__n[807-43] = 0;
	__flag121__n[808-43] = 0;
	__flag121__n[809-43] = 0;
	__flag121__n[810-43] = 0;
	__flag121__n[811-43] = 0;
	__flag121__n[812-43] = 0;
	__flag121__n[813-43] = 0;
	__flag121__n[814-43] = 0;
	__flag121__n[815-43] = 0;
	__flag121__n[816-43] = 0;
	__flag121__n[817-43] = 0;
	__flag121__n[818-43] = 0;
	__flag121__n[831-43] = 0;
	__flag121__n[832-43] = 0;
	__flag121__n[833-43] = 0;
	__flag121__n[834-43] = 0;
	__flag121__n[835-43] = 0;
	__flag121__n[836-43] = 0;
	__flag121__n[837-43] = 0;
	__flag121__n[838-43] = 0;
	__flag121__n[839-43] = 0;
	__flag121__n[840-43] = 0;
	__flag121__n[841-43] = 0;
	__flag121__n[842-43] = 0;
	__flag121__n[843-43] = 0;
	__flag121__n[844-43] = 0;
	__flag121__n[845-43] = 0;
	__flag121__n[846-43] = 0;
	__flag121__n[847-43] = 0;
	__flag121__n[848-43] = 0;
	__flag121__n[849-43] = 0;
	__flag121__n[850-43] = 0;
	__flag122__n[49-43] = 0;
	__flag122__n[50-43] = 0;
	__flag122__n[51-43] = 0;
	__flag122__n[52-43] = 0;
	__flag122__n[53-43] = 0;
	__flag122__n[54-43] = 0;
	__flag122__n[55-43] = 0;
	__flag122__n[56-43] = 0;
	__flag122__n[57-43] = 0;
	__flag122__n[58-43] = 0;
	__flag122__n[59-43] = 0;
	__flag122__n[60-43] = 0;
	__flag122__n[61-43] = 0;
	__flag122__n[62-43] = 0;
	__flag122__n[63-43] = 0;
	__flag122__n[64-43] = 0;
	__flag122__n[65-43] = 0;
	__flag122__n[66-43] = 0;
	__flag122__n[67-43] = 0;
	__flag122__n[68-43] = 0;
	__flag122__n[81-43] = 0;
	__flag122__n[82-43] = 0;
	__flag122__n[83-43] = 0;
	__flag122__n[84-43] = 0;
	__flag122__n[85-43] = 0;
	__flag122__n[86-43] = 0;
	__flag122__n[87-43] = 0;
	__flag122__n[88-43] = 0;
	__flag122__n[89-43] = 0;
	__flag122__n[90-43] = 0;
	__flag122__n[91-43] = 0;
	__flag122__n[92-43] = 0;
	__flag122__n[93-43] = 0;
	__flag122__n[94-43] = 0;
	__flag122__n[95-43] = 0;
	__flag122__n[96-43] = 0;
	__flag122__n[113-43] = 0;
	__flag122__n[114-43] = 0;
	__flag122__n[115-43] = 0;
	__flag122__n[116-43] = 0;
	__flag122__n[117-43] = 0;
	__flag122__n[118-43] = 0;
	__flag122__n[119-43] = 0;
	__flag122__n[120-43] = 0;
	__flag122__n[121-43] = 0;
	__flag122__n[122-43] = 0;
	__flag122__n[123-43] = 0;
	__flag122__n[124-43] = 0;
	__flag122__n[125-43] = 0;
	__flag122__n[144-43] = 0;
	__flag122__n[145-43] = 0;
	__flag122__n[146-43] = 0;
	__flag122__n[147-43] = 0;
	__flag122__n[148-43] = 0;
	__flag122__n[149-43] = 0;
	__flag122__n[150-43] = 0;
	__flag122__n[151-43] = 0;
	__flag122__n[152-43] = 0;
	__flag122__n[153-43] = 0;
	__flag122__n[154-43] = 0;
	__flag122__n[175-43] = 0;
	__flag122__n[176-43] = 0;
	__flag122__n[177-43] = 0;
	__flag122__n[178-43] = 0;
	__flag122__n[179-43] = 0;
	__flag122__n[180-43] = 0;
	__flag122__n[181-43] = 0;
	__flag122__n[182-43] = 0;
	__flag122__n[183-43] = 0;
	__flag122__n[206-43] = 0;
	__flag122__n[207-43] = 0;
	__flag122__n[208-43] = 0;
	__flag122__n[209-43] = 0;
	__flag122__n[210-43] = 0;
	__flag122__n[211-43] = 0;
	__flag122__n[212-43] = 0;
	__flag122__n[237-43] = 0;
	__flag122__n[238-43] = 0;
	__flag122__n[239-43] = 0;
	__flag122__n[240-43] = 0;
	__flag122__n[241-43] = 0;
	__flag122__n[242-43] = 0;
	__flag122__n[267-43] = 0;
	__flag122__n[268-43] = 0;
	__flag122__n[269-43] = 0;
	__flag122__n[270-43] = 0;
	__flag122__n[271-43] = 0;
	__flag122__n[284-43] = 0;
	__flag122__n[285-43] = 0;
	__flag122__n[298-43] = 0;
	__flag122__n[299-43] = 0;
	__flag122__n[300-43] = 0;
	__flag122__n[301-43] = 0;
	__flag122__n[312-43] = 0;
	__flag122__n[313-43] = 0;
	__flag122__n[314-43] = 0;
	__flag122__n[315-43] = 0;
	__flag122__n[316-43] = 0;
	__flag122__n[317-43] = 0;
	__flag122__n[328-43] = 0;
	__flag122__n[329-43] = 0;
	__flag122__n[330-43] = 0;
	__flag122__n[341-43] = 0;
	__flag122__n[342-43] = 0;
	__flag122__n[343-43] = 0;
	__flag122__n[344-43] = 0;
	__flag122__n[345-43] = 0;
	__flag122__n[346-43] = 0;
	__flag122__n[347-43] = 0;
	__flag122__n[348-43] = 0;
	__flag122__n[359-43] = 0;
	__flag122__n[360-43] = 0;
	__flag122__n[370-43] = 0;
	__flag122__n[371-43] = 0;
	__flag122__n[372-43] = 0;
	__flag122__n[373-43] = 0;
	__flag122__n[374-43] = 0;
	__flag122__n[375-43] = 0;
	__flag122__n[376-43] = 0;
	__flag122__n[377-43] = 0;
	__flag122__n[378-43] = 0;
	__flag122__n[379-43] = 0;
	__flag122__n[389-43] = 0;
	__flag122__n[390-43] = 0;
	__flag122__n[400-43] = 0;
	__flag122__n[401-43] = 0;
	__flag122__n[402-43] = 0;
	__flag122__n[403-43] = 0;
	__flag122__n[404-43] = 0;
	__flag122__n[405-43] = 0;
	__flag122__n[406-43] = 0;
	__flag122__n[407-43] = 0;
	__flag122__n[408-43] = 0;
	__flag122__n[409-43] = 0;
	__flag122__n[419-43] = 0;
	__flag122__n[420-43] = 0;
	__flag122__n[429-43] = 0;
	__flag122__n[430-43] = 0;
	__flag122__n[431-43] = 0;
	__flag122__n[432-43] = 0;
	__flag122__n[433-43] = 0;
	__flag122__n[434-43] = 0;
	__flag122__n[435-43] = 0;
	__flag122__n[436-43] = 0;
	__flag122__n[437-43] = 0;
	__flag122__n[438-43] = 0;
	__flag122__n[439-43] = 0;
	__flag122__n[440-43] = 0;
	__flag122__n[449-43] = 0;
	__flag122__n[450-43] = 0;
	__flag122__n[459-43] = 0;
	__flag122__n[460-43] = 0;
	__flag122__n[461-43] = 0;
	__flag122__n[462-43] = 0;
	__flag122__n[463-43] = 0;
	__flag122__n[464-43] = 0;
	__flag122__n[465-43] = 0;
	__flag122__n[466-43] = 0;
	__flag122__n[467-43] = 0;
	__flag122__n[468-43] = 0;
	__flag122__n[469-43] = 0;
	__flag122__n[470-43] = 0;
	__flag122__n[479-43] = 0;
	__flag122__n[480-43] = 0;
	__flag122__n[490-43] = 0;
	__flag122__n[491-43] = 0;
	__flag122__n[492-43] = 0;
	__flag122__n[493-43] = 0;
	__flag122__n[494-43] = 0;
	__flag122__n[495-43] = 0;
	__flag122__n[496-43] = 0;
	__flag122__n[497-43] = 0;
	__flag122__n[498-43] = 0;
	__flag122__n[499-43] = 0;
	__flag122__n[509-43] = 0;
	__flag122__n[510-43] = 0;
	__flag122__n[520-43] = 0;
	__flag122__n[521-43] = 0;
	__flag122__n[522-43] = 0;
	__flag122__n[523-43] = 0;
	__flag122__n[524-43] = 0;
	__flag122__n[525-43] = 0;
	__flag122__n[526-43] = 0;
	__flag122__n[527-43] = 0;
	__flag122__n[528-43] = 0;
	__flag122__n[529-43] = 0;
	__flag122__n[539-43] = 0;
	__flag122__n[540-43] = 0;
	__flag122__n[551-43] = 0;
	__flag122__n[552-43] = 0;
	__flag122__n[553-43] = 0;
	__flag122__n[554-43] = 0;
	__flag122__n[555-43] = 0;
	__flag122__n[556-43] = 0;
	__flag122__n[557-43] = 0;
	__flag122__n[558-43] = 0;
	__flag122__n[569-43] = 0;
	__flag122__n[570-43] = 0;
	__flag122__n[571-43] = 0;
	__flag122__n[582-43] = 0;
	__flag122__n[583-43] = 0;
	__flag122__n[584-43] = 0;
	__flag122__n[585-43] = 0;
	__flag122__n[586-43] = 0;
	__flag122__n[587-43] = 0;
	__flag122__n[598-43] = 0;
	__flag122__n[599-43] = 0;
	__flag122__n[600-43] = 0;
	__flag122__n[601-43] = 0;
	__flag122__n[614-43] = 0;
	__flag122__n[615-43] = 0;
	__flag122__n[628-43] = 0;
	__flag122__n[629-43] = 0;
	__flag122__n[630-43] = 0;
	__flag122__n[631-43] = 0;
	__flag122__n[632-43] = 0;
	__flag122__n[657-43] = 0;
	__flag122__n[658-43] = 0;
	__flag122__n[659-43] = 0;
	__flag122__n[660-43] = 0;
	__flag122__n[661-43] = 0;
	__flag122__n[662-43] = 0;
	__flag122__n[687-43] = 0;
	__flag122__n[688-43] = 0;
	__flag122__n[689-43] = 0;
	__flag122__n[690-43] = 0;
	__flag122__n[691-43] = 0;
	__flag122__n[692-43] = 0;
	__flag122__n[693-43] = 0;
	__flag122__n[716-43] = 0;
	__flag122__n[717-43] = 0;
	__flag122__n[718-43] = 0;
	__flag122__n[719-43] = 0;
	__flag122__n[720-43] = 0;
	__flag122__n[721-43] = 0;
	__flag122__n[722-43] = 0;
	__flag122__n[723-43] = 0;
	__flag122__n[724-43] = 0;
	__flag122__n[745-43] = 0;
	__flag122__n[746-43] = 0;
	__flag122__n[747-43] = 0;
	__flag122__n[748-43] = 0;
	__flag122__n[749-43] = 0;
	__flag122__n[750-43] = 0;
	__flag122__n[751-43] = 0;
	__flag122__n[752-43] = 0;
	__flag122__n[753-43] = 0;
	__flag122__n[754-43] = 0;
	__flag122__n[755-43] = 0;
	__flag122__n[774-43] = 0;
	__flag122__n[775-43] = 0;
	__flag122__n[776-43] = 0;
	__flag122__n[777-43] = 0;
	__flag122__n[778-43] = 0;
	__flag122__n[779-43] = 0;
	__flag122__n[780-43] = 0;
	__flag122__n[781-43] = 0;
	__flag122__n[782-43] = 0;
	__flag122__n[783-43] = 0;
	__flag122__n[784-43] = 0;
	__flag122__n[785-43] = 0;
	__flag122__n[786-43] = 0;
	__flag122__n[803-43] = 0;
	__flag122__n[804-43] = 0;
	__flag122__n[805-43] = 0;
	__flag122__n[806-43] = 0;
	__flag122__n[807-43] = 0;
	__flag122__n[808-43] = 0;
	__flag122__n[809-43] = 0;
	__flag122__n[810-43] = 0;
	__flag122__n[811-43] = 0;
	__flag122__n[812-43] = 0;
	__flag122__n[813-43] = 0;
	__flag122__n[814-43] = 0;
	__flag122__n[815-43] = 0;
	__flag122__n[816-43] = 0;
	__flag122__n[817-43] = 0;
	__flag122__n[818-43] = 0;
	__flag122__n[831-43] = 0;
	__flag122__n[832-43] = 0;
	__flag122__n[833-43] = 0;
	__flag122__n[834-43] = 0;
	__flag122__n[835-43] = 0;
	__flag122__n[836-43] = 0;
	__flag122__n[837-43] = 0;
	__flag122__n[838-43] = 0;
	__flag122__n[839-43] = 0;
	__flag122__n[840-43] = 0;
	__flag122__n[841-43] = 0;
	__flag122__n[842-43] = 0;
	__flag122__n[843-43] = 0;
	__flag122__n[844-43] = 0;
	__flag122__n[845-43] = 0;
	__flag122__n[846-43] = 0;
	__flag122__n[847-43] = 0;
	__flag122__n[848-43] = 0;
	__flag122__n[849-43] = 0;
	__flag122__n[850-43] = 0;


	/* REVISION: variable for print interval */
	int timeCount = 0;
	double nodeSum = 0.0;
	double nodeSumX = 0.0;
	double nodeSumY = 0.0;

	/*Revision*/
	for(membrane_time = 0.000000; ( membrane_time <= 500.000000 ) ;membrane_time =  ( membrane_time + deltat ) ){

			//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
//			n = (double)100;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
//			i = (double)100;
		//------------------------------- END -------------------------------//

		/* REVISION: correct the indexing TODO: correct the indexing in the getSyntaxProgram */
		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			slow_inward_current_f_gate_beta_f__n[__i] =  (  (  (  ( (double)0.0065 * exp(  (  ( - (double)0.02 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.2 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( slow_inward_current_f_gate_beta_f__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			plateau_potassium_current_Kp__n[__i] =  (  (  ( (double)1 /  ( (double)1 + exp(  (  ( (double)7.488 - membrane_V__n[__i] )  / (double)5.98 )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( plateau_potassium_current_Kp__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			slow_inward_current_f_gate_alpha_f__n[__i] =  (  (  (  ( (double)0.012 * exp(  (  ( - (double)0.008 )  *  ( membrane_V__n[__i] + (double)28 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.15 *  ( membrane_V__n[__i] + (double)28 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			slow_inward_current_d_gate_alpha_d__n[__i] =  (  (  (  ( (double)0.095 * exp(  (  ( - (double)0.01 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.072 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			slow_inward_current_d_gate_beta_d__n[__i] =  (  (  (  ( (double)0.07 * exp(  (  ( - (double)0.017 )  *  ( membrane_V__n[__i] + (double)44 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.05 *  ( membrane_V__n[__i] + (double)44 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( slow_inward_current_d_gate_beta_d__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			slow_inward_current_E_si__n[__i] =  (  (  ( (double)7.7 -  ( (double)13.0287 * log(  ( slow_inward_current_Cai__n[__i] / (double)1 )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( slow_inward_current_E_si__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			membrane_i_b__n[__i] =  (  (  ( background_current_g_b *  ( membrane_V__n[__i] - background_current_E_b )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( membrane_i_b__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_j_gate_beta_j__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)0.1212 * exp(  (  ( - (double)0.01052 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1378 )  *  ( membrane_V__n[__i] + (double)40.14 )  )  ) )  )  :  (  ( (double)0.3 * exp(  (  ( - (double)0.0000002535 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)32 )  )  ) )  )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_j_gate_beta_j__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_dependent_potassium_current_g_K__n[__i] =  (  (  ( time_dependent_potassium_current_g_Kbar * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_g_K__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_dependent_potassium_current_E_K__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  (  ( time_independent_potassium_current_Ko +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nao )  )  /  ( time_independent_potassium_current_Ki +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nai )  )  )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_E_K__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_dependent_potassium_current_X_gate_alpha_X__n[__i] =  (  (  (  ( (double)0.0005 * exp(  ( (double)0.083 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.057 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_dependent_potassium_current_X_gate_beta_X__n[__i] =  (  (  (  ( (double)0.0013 * exp(  (  ( - (double)0.06 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.04 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_dependent_potassium_current_Xi__n[__i] =  (  (  (  ( membrane_V__n[__i] >  ( - (double)100 )  )  ?  (  ( (double)2.837 *  ( exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)77 )  )  ) - (double)1 )  )  /  (  ( membrane_V__n[__i] + (double)77 )  * exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)35 )  )  ) )  )  : (double)1 )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_Xi__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_independent_potassium_current_g_K1__n[__i] =  (  (  ( (double)0.6047 * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_independent_potassium_current_g_K1__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			time_independent_potassium_current_E_K1__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_independent_potassium_current_Ko / time_independent_potassium_current_Ki )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( time_independent_potassium_current_E_K1__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_E_Na__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_dependent_potassium_current_Nao / time_dependent_potassium_current_Nai )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_E_Na__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_j_gate_alpha_j__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  (  (  (  ( - (double)127140 )  * exp(  ( (double)0.2444 * membrane_V__n[__i] )  ) )  -  ( (double)0.00003474 * exp(  (  ( - (double)0.04391 )  * membrane_V__n[__i] )  ) )  )  *  ( membrane_V__n[__i] + (double)37.78 )  )  /  ( (double)1 + exp(  ( (double)0.311 *  ( membrane_V__n[__i] + (double)79.23 )  )  ) )  )  : (double)0 )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_h_gate_alpha_h__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  ( (double)0.135 * exp(  (  ( (double)80 + membrane_V__n[__i] )  /  ( - (double)6.8 )  )  ) )  : (double)0 )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_m_gate_beta_m__n[__i] =  (  (  ( (double)0.08 * exp(  (  ( - membrane_V__n[__i] )  / (double)11 )  ) )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_m_gate_beta_m__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_m_gate_alpha_m__n[__i] =  (  (  (  ( (double)0.32 *  ( membrane_V__n[__i] + (double)47.13 )  )  /  ( (double)1 - exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)47.13 )  )  ) )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
			fast_sodium_current_h_gate_beta_h__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)3.56 * exp(  ( (double)0.079 * membrane_V__n[__i] )  ) )  +  ( (double)310000 * exp(  ( (double)0.35 * membrane_V__n[__i] )  ) )  )  :  ( (double)1 /  ( (double)0.13 *  ( (double)1 + exp(  (  ( membrane_V__n[__i] + (double)10.66 )  /  ( - (double)11.1 )  )  ) )  )  )  )  * __flag2__n[ ( __i - 43 ) ] )  +  ( fast_sodium_current_h_gate_beta_h__n[__i] *  ( 1 - __flag2__n[ ( __i - 43 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		/*MPI_Allgather関数でmembrane_V__nを全ノードに持たせる*/
		//if(myrank == root) st = MPI_Wtime();
		MPI_Allgather(&membrane_V__n[sourcebuf], calcindex, MPI_DOUBLE, &membrane_V__n_temp[43], calcindex, MPI_DOUBLE, MPI_COMM_WORLD);
		//if(myrank == root) en = MPI_Wtime();

		for(__i=43; __i<=858; __i++){
			 membrane_V__n[__i] = membrane_V__n_temp[__i] ;
		}

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//	X0end = X0end;
		//------------------------------- END -------------------------------//

		/* REVISION: correct the boundary condition equations (remove unneccessary flags) */

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=13; __i<=41; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i + 30 ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:42 end:42 ----------------------------//
			 membrane_V__n[42] = membrane_V__n[43] ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=49; __i<=67; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i + 30 ) ]  ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:68 end:68 ----------------------------//
			 membrane_V__n[68] = membrane_V__n[69] ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=81; __i<=82; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i + 30 ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:96 end:96 ----------------------------//
			 membrane_V__n[96] = membrane_V__n[97] ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:113 end:113 ----------------------------//
			 membrane_V__n[113] = membrane_V__n[143] ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:125 end:125 ----------------------------//
			 membrane_V__n[125] = membrane_V__n[126] ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=144; __i<=144; __i++){
			 membrane_V__n[144] = membrane_V__n[143] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=154; __i<=154; __i++){
			 membrane_V__n[154] = membrane_V__n[155] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=175; __i<=175; __i++){
			 membrane_V__n[175] = membrane_V__n[205] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=183; __i<=183; __i++){
			 membrane_V__n[183] = membrane_V__n[184] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=206; __i<=206; __i++){
			 membrane_V__n[206] = membrane_V__n[205] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=212; __i<=212; __i++){
			 membrane_V__n[212] = membrane_V__n[213] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=237; __i<=237; __i++){
			 membrane_V__n[237] = membrane_V__n[236] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=242; __i<=242; __i++){
			 membrane_V__n[242] = membrane_V__n[243] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=267; __i<=267; __i++){
			 membrane_V__n[267] = membrane_V__n[297] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=271; __i<=271; __i++){
			 membrane_V__n[271] = membrane_V__n[272] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=284; __i<=284; __i++){
			 membrane_V__n[284] = membrane_V__n[254] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=285; __i<=285; __i++){
			 membrane_V__n[285] = membrane_V__n[286] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=298; __i<=298; __i++){
			 membrane_V__n[298] = membrane_V__n[297] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=301; __i<=301; __i++){
			 membrane_V__n[301] = membrane_V__n[302] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=312; __i<=317; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i +  ( - 30 )  ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=328; __i<=328; __i++){
			 membrane_V__n[328] = membrane_V__n[327] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortes= membrane_V__n[der:0
		//---------------------------- LOOP ----------------------------//
		for(__i=330; __i<=330; __i++){
			 membrane_V__n[330] = membrane_V__n[331] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=341; __i<=341; __i++){
			 membrane_V__n[341] = membrane_V__n[311] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=348; __i<=348; __i++){
			 membrane_V__n[348] = membrane_V__n[349] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=359; __i<=359; __i++){
			 membrane_V__n[359] = membrane_V__n[358] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=360; __i<=360; __i++){
			 membrane_V__n[360] = membrane_V__n[361] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=370; __i<=379; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i +  ( - 30 )  ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=389; __i<=389; __i++){
			 membrane_V__n[389] = membrane_V__n[388] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortes= membrane_V__n[der:0
		//---------------------------- LOOP ----------------------------//
		for(__i=390; __i<=390; __i++){
			 membrane_V__n[390] = membrane_V__n[391] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=400; __i<=400; __i++){
			 membrane_V__n[400] = membrane_V__n[399] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=409; __i<=409; __i++){
			 membrane_V__n[409] = membrane_V__n[410] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=419; __i<=419; __i++){
			 membrane_V__n[419] = membrane_V__n[418] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=420; __i<=420; __i++){
			 membrane_V__n[420] = membrane_V__n[421] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=429; __i<=429; __i++){
			 membrane_V__n[429] = membrane_V__n[399] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=440; __i<=440; __i++){
			 membrane_V__n[440] = membrane_V__n[441] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=449; __i<=449; __i++){
			 membrane_V__n[449] = membrane_V__n[448] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=450; __i<=450; __i++){
			 membrane_V__n[450] = membrane_V__n[451] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=459; __i<=459; __i++){
			 membrane_V__n[459] = membrane_V__n[489] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=470; __i<=470; __i++){
			 membrane_V__n[470] = membrane_V__n[471] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=479; __i<=479; __i++){
			 membrane_V__n[479] = membrane_V__n[478] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=480; __i<=480; __i++){
			 membrane_V__n[480] = membrane_V__n[481] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=490; __i<=490; __i++){
			 membrane_V__n[490] = membrane_V__n[489] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=499; __i<=499; __i++){
			 membrane_V__n[499] = membrane_V__n[500] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=509; __i<=509; __i++){
			 membrane_V__n[509] = membrane_V__n[508] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=510; __i<=510; __i++){
			 membrane_V__n[510] = membrane_V__n[511] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=520; __i<=529; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i + 30 ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=539; __i<=539; __i++){
			 membrane_V__n[539] = membrane_V__n[538] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=540; __i<=540; __i++){
			 membrane_V__n[540] = membrane_V__n[541] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=551; __i<=551; __i++){
			 membrane_V__n[551] = membrane_V__n[581] ;
		}
		//----------------------------- LOOP END --------membrane_V__n[-----//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=558; __i<=558; __i++){
			 membrane_V__n[558] = membrane_V__n[559] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=569; __i<=569; __i++){
			 membrane_V__n[569] = membrane_V__n[568] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=571; __i<=571; __i++){
			 membrane_V__n[571] = membrane_V__n[572] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=582; __i<=587; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i + 30 ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=598; __i<=598; __i++){
			 membrane_V__n[598] = membrane_V__n[597] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=601; __i<=601; __i++){
			 membrane_V__n[601] = membrane_V__n[602] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=614; __i<=614; __i++){
			 membrane_V__n[614] = membrane_V__n[644] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=615; __i<=615; __i++){
			 membrane_V__n[615] = membrane_V__n[616] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=628; __i<=628; __i++){
			 membrane_V__n[628] = membrane_V__n[627] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=632; __i<=632; __i++){
			 membrane_V__n[632] = membrane_V__n[633] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=657; __i<=657; __i++){
			 membrane_V__n[657] = membrane_V__n[627] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=662; __i<=662; __i++){
			 membrane_V__n[662] = membrane_V__n[663] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=687; __i<=687; __i++){
			 membrane_V__n[687] = membrane_V__n[686] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=693; __i<=693; __i++){
			 membrane_V__n[693] = membrane_V__n[694] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=716; __i<=716; __i++){
			 membrane_V__n[716] = membrane_V__n[715] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=724; __i<=724; __i++){
			 membrane_V__n[724] = membrane_V__n[725] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=745; __i<=745; __i++){
			 membrane_V__n[745] = membrane_V__n[715] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=755; __i<=755; __i++){
			 membrane_V__n[755] = membrane_V__n[756] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=774; __i<=774; __i++){
			 membrane_V__n[774] = membrane_V__n[773] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=786; __i<=786; __i++){
			 membrane_V__n[786] = membrane_V__n[787] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=803; __i<=817; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i +  ( - 30 )  ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=818; __i<=818; __i++){
			 membrane_V__n[818] = membrane_V__n[819] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=831; __i<=849; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i +  ( - 30 )  ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=850; __i<=850; __i++){
			 membrane_V__n[850] = membrane_V__n[851] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=859; __i<=888; __i++){
			 membrane_V__n[__i] = membrane_V__n[ ( __i +  ( - 30 )  ) ] ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//	X1end = X1end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//	V0end = V0end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//	V1end = V1end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
		//	membrane_time = membrane_time;
		//------------------------------- END -------------------------------//

		/* REVISION: added the equation with differential equations TODO: revise the stimulation equation */
		//Shortest Calculation Order:1
		//---------------------------- LOOP ----------------------------//
		double stim = 0;

		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			slow_inward_current_d__n1[__i] =  ( ( slow_inward_current_d__n[__i] + deltat * (  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( (double)1 - slow_inward_current_d__n[__i] )  )  -  ( slow_inward_current_d_gate_beta_d__n[__i] * slow_inward_current_d__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  + ( slow_inward_current_d__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			fast_sodium_current_j__n1[__i] =  ( ( fast_sodium_current_j__n[__i] + deltat * (  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( (double)1 - fast_sodium_current_j__n[__i] )  )  -  ( fast_sodium_current_j_gate_beta_j__n[__i] * fast_sodium_current_j__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  + ( fast_sodium_current_j__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			slow_inward_current_f__n1[__i] =  ( ( slow_inward_current_f__n[__i] + deltat * (  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( (double)1 - slow_inward_current_f__n[__i] )  )  -  ( slow_inward_current_f_gate_beta_f__n[__i] * slow_inward_current_f__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  + ( slow_inward_current_f__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			time_dependent_potassium_current_X__n1[__i] =  ( ( time_dependent_potassium_current_X__n[__i] + deltat * (  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( (double)1 - time_dependent_potassium_current_X__n[__i] )  )  -  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] * time_dependent_potassium_current_X__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  +  ( time_dependent_potassium_current_X__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			fast_sodium_current_m__n1[__i] =  ( ( fast_sodium_current_m__n[__i] + deltat * (  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( (double)1 - fast_sodium_current_m__n[__i] )  )  -  ( fast_sodium_current_m_gate_beta_m__n[__i] * fast_sodium_current_m__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  + ( fast_sodium_current_m__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			fast_sodium_current_h__n1[__i] =  ( ( fast_sodium_current_h__n[__i] + deltat * (  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( (double)1 - fast_sodium_current_h__n[__i] )  )  -  ( fast_sodium_current_h_gate_beta_h__n[__i] * fast_sodium_current_h__n[__i] )  ) ) * __flag105__n[ ( __i - 43 ) ] )  + ( fast_sodium_current_h__n1[__i] * ( 1 - __flag105__n[ ( __i - 43 ) ] ) ) ;
			membrane_i_si__n[__i] =  (  (  ( (double)0.09 * slow_inward_current_d__n[__i] * slow_inward_current_f__n[__i] *  ( membrane_V__n[__i] - slow_inward_current_E_si__n[__i] )  )  * __flag105__n[ ( __i - 43 ) ] )  +  ( membrane_i_si__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			membrane_i_K__n[__i] =  (  (  ( time_dependent_potassium_current_g_K__n[__i] * time_dependent_potassium_current_X__n[__i] * time_dependent_potassium_current_Xi__n[__i] *  ( membrane_V__n[__i] - time_dependent_potassium_current_E_K__n[__i] )  )  * __flag105__n[ ( __i - 43 ) ] )  +  ( membrane_i_K__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			time_independent_potassium_current_K1_gate_beta_K1__n[__i] =  (  (  (  (  ( (double)0.49124 * exp(  ( (double)0.08032 *  (  ( membrane_V__n[__i] + (double)5.476 )  - time_independent_potassium_current_E_K1__n[__i] )  )  ) )  +  ( (double)1 * exp(  ( (double)0.06175 *  ( membrane_V__n[__i] -  ( time_independent_potassium_current_E_K1__n[__i] + (double)594.31 )  )  )  ) )  )  /  ( (double)1 + exp(  (  ( - (double)0.5143 )  *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  + (double)4.753 )  )  ) )  )  * __flag105__n[ ( __i - 43 ) ] )  +  ( time_independent_potassium_current_K1_gate_beta_K1__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			plateau_potassium_current_E_Kp__n[__i] =  (  ( time_independent_potassium_current_E_K1__n[__i] * __flag105__n[ ( __i - 43 ) ] )  +  ( plateau_potassium_current_E_Kp__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			time_independent_potassium_current_K1_gate_alpha_K1__n[__i] =  (  (  ( (double)1.02 /  ( (double)1 + exp(  ( (double)0.2385 *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  - (double)59.215 )  )  ) )  )  * __flag105__n[ ( __i - 43 ) ] )  +  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			membrane_i_Na__n[__i] =  (  (  ( fast_sodium_current_g_Na * pow( fast_sodium_current_m__n[__i] , (double)3 ) * fast_sodium_current_h__n[__i] * fast_sodium_current_j__n[__i] *  ( membrane_V__n[__i] - fast_sodium_current_E_Na__n[__i] )  )  * __flag105__n[ ( __i - 43 ) ] )  +  ( membrane_i_Na__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			/* REVISION: revise the stimulation equations apply if else TODO: see if it can be done manually, else make Istim = 0; */
			if (__i>=43 && __i<48) {
				membrane_I_stim__n[__i] =  (  (  (  (  ( membrane_time >= membrane_stim_start )  &&  ( membrane_time <= membrane_stim_end )  &&  (  (  ( membrane_time - membrane_stim_start )  -  ( floor(  (  ( membrane_time - membrane_stim_start )  / membrane_stim_period )  ) * membrane_stim_period )  )  <= membrane_stim_duration )  )  ? membrane_stim_amplitude : (double)0 )  * __flag105__n[ ( __i - 43 ) ] )  +  ( membrane_I_stim__n[__i] *  ( 1 - __flag105__n[ ( __i - 43 ) ] )  )  ) ;
			} else {
				membrane_I_stim__n[__i] =  0 ;
			}
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:2
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			slow_inward_current_Cai__n1[__i] = ( ( slow_inward_current_Cai__n[__i] + deltat * (  (  (  ( - (double)0.0001 )  / (double)1 )  * membrane_i_si__n[__i] )  +  ( (double)0.07 *  ( (double)0.0001 - slow_inward_current_Cai__n[__i] )  )  ) ) * __flag118__n[ ( __i - 43 ) ] ) + ( slow_inward_current_Cai__n1[__i] * ( 1 - __flag118__n[ ( __i - 43 ) ] ) );
			membrane_i_Kp__n[__i] =  (  (  ( plateau_potassium_current_g_Kp * plateau_potassium_current_Kp__n[__i] *  ( membrane_V__n[__i] - plateau_potassium_current_E_Kp__n[__i] )  )  * __flag118__n[ ( __i - 43 ) ] )  +  ( membrane_i_Kp__n[__i] *  ( 1 - __flag118__n[ ( __i - 43 ) ] )  )  ) ;
			time_independent_potassium_current_K1_infinity__n[__i] =  (  (  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] /  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] + time_independent_potassium_current_K1_gate_beta_K1__n[__i] )  )  * __flag118__n[ ( __i - 43 ) ] )  +  ( time_independent_potassium_current_K1_infinity__n[__i] *  ( 1 - __flag118__n[ ( __i - 43 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:3
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			membrane_i_K1__n[__i] =  (  (  ( time_independent_potassium_current_g_K1__n[__i] * time_independent_potassium_current_K1_infinity__n[__i] *  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  )  * __flag121__n[ ( __i - 43 ) ] )  +  ( membrane_i_K1__n[__i] *  ( 1 - __flag121__n[ ( __i - 43 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:4
		//---------------------------- LOOP ----------------------------//
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			membrane_V__n1[__i]  =  (  (  ( membrane_V__n[__i] + deltat * ( (  (  ( - (double)1 )  / membrane_C )  *  ( membrane_I_stim__n[__i] + membrane_i_Na__n[__i] + membrane_i_si__n[__i] + membrane_i_K__n[__i] + membrane_i_K1__n[__i] + membrane_i_Kp__n[__i] + membrane_i_b__n[__i] )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( __i + 1 ) ] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[__i-1] )  /  ( deltax1 * deltax1 )  )  )  +  ( membrane_D *  (  ( membrane_V__n[__i+30] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[__i-30] )  /  ( deltax2 * deltax2 )  )  )  ) ) * __flag122__n[ ( __i - 43 ) ] )  +  (  membrane_V__n1[__i]  *  ( 1 - __flag122__n[ ( __i - 43 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: print current time */
		/*if(myrank == root){
			if (timeCount % 100 == 0) {
				printf("%f ", membrane_time);
			}
		}*/

		/* REVISION: reassign the results of index n1(n+1) to index n TODO: harmonize with structured relml version */
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=43; __i<=858; __i++){
			fast_sodium_current_j__n[__i] = fast_sodium_current_j__n1[__i];
			fast_sodium_current_h__n[__i] = fast_sodium_current_h__n1[__i];
			slow_inward_current_d__n[__i] = slow_inward_current_d__n1[__i];
			time_dependent_potassium_current_X__n[__i] = time_dependent_potassium_current_X__n1[__i];
			fast_sodium_current_m__n[__i] = fast_sodium_current_m__n1[__i];
			slow_inward_current_f__n[__i] = slow_inward_current_f__n1[__i];
			membrane_V__n[__i] = membrane_V__n1[__i];
			/* REVISION: print a partial part of results (oppossite ends of the morphology) */
			/*if(myrank == root){
				if (timeCount % 100 == 0) {
					if ( __i>=43 && __i<51) {
						printf("%f ", membrane_V__n1[__i]);
					}
					if ( __i>=850 && __i<858) {
						printf("%f ", membrane_V__n1[__i]);
					}
				}
			}*/
		}

		/* REVISION: print a partial part of results */
		/*if(myrank == root){
			if (timeCount % 100 == 0) {
				printf("\n");
			}
		}*/

		/*通信時間計測出力*/
		/*if(myrank == root){
			if (timeCount % 100 == 0) {
				printf("%.6f\n", en-st);
			}
		}*/

		/* REVISION: insert time counter */
		timeCount =  ( timeCount + 1 ) ;

	}

	/*membrane_V__n_tempの開放*/
	free ( membrane_V__n_temp ) ;

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
	free ( __flag2__n ) ;
	free ( __flag24__n ) ;
	free ( __flag26__n ) ;
	free ( __flag46__n ) ;
	free ( __flag53__n ) ;
	free ( __flag72__n ) ;
	free ( __flag79__n ) ;
	free ( __flag96__n ) ;
	free ( __flag98__n ) ;
	free ( __flag100__n ) ;
	free ( __flag105__n ) ;
	free ( __flag118__n ) ;
	free ( __flag121__n ) ;
	free ( __flag122__n ) ;

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


