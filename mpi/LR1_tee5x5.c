/*
 * LR1_tee5x5.c
 *
 *  Created on: 2013/05/24
 *      Author: fr-punzalan
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "mpi.h"

#define __MAX_TIME_NUM 500.0
#define __MAX_DATA_NUM 25


int main ( int argc , char** argv ) ;

int main ( int argc , char** argv ) {
	int myrank;
	int nodenum;
	const int root=0;//rootを親とする
	/*MPI 初期化*/
	MPI_Init(&argc,&argv);
	/*MPI ランクを取得*/
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	/*クラスタの台数取得*/
	MPI_Comm_size(MPI_COMM_WORLD,&nodenum);


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

	/* REVISION: make index an int TODO: find a way to distinguish index variable */
	//int __i;
	//int n;
	double* membrane_I_stim__n;
	double* membrane_V__n;
	double* membrane_V__n1;
	double* membrane_i_K1__n;
	double* membrane_i_K__n;
	double* membrane_i_Kp__n;
	double* membrane_i_Na__n;
	double* membrane_i_b__n;
	double* membrane_i_si__n;

	/* REVISION: change time declarations from double* to double */
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
	double* __flag36__n;
	double* __flag49__n;
	double* __flag52__n;
	double* __flag53__n;
	int __i;

	V0end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	V1end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	X0end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	X1end = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_E_Na__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_h__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_h_gate_alpha_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_h_gate_beta_h__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_j__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_j_gate_alpha_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_j_gate_beta_j__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_m__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_m_gate_alpha_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	fast_sodium_current_m_gate_beta_m__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	//i = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_I_stim__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_V__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_V__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_Na__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_b__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	membrane_i_si__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;

	/* REVISION: removed membrane_time malloc */
	//n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	plateau_potassium_current_E_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	plateau_potassium_current_Kp__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_Cai__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_Cai__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_E_si__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_d__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_d_gate_alpha_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_d_gate_beta_d__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_f__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_f_gate_alpha_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	slow_inward_current_f_gate_beta_f__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_E_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_X__n1 = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_X_gate_alpha_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_X_gate_beta_X__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_Xi__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_dependent_potassium_current_g_K__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_independent_potassium_current_E_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_independent_potassium_current_K1_gate_alpha_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_independent_potassium_current_K1_gate_beta_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_independent_potassium_current_K1_infinity__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	time_independent_potassium_current_g_K1__n = malloc (  ( sizeof( double ) * __MAX_DATA_NUM )  ) ; ;
	__flag2__n = malloc (  ( sizeof( double ) * 17-6+1 )  ) ; ;
	__flag36__n = malloc (  ( sizeof( double ) * 17-6+1 )  ) ; ;
	__flag49__n = malloc (  ( sizeof( double ) * 17-6+1 )  ) ; ;
	__flag52__n = malloc (  ( sizeof( double ) * 17-6+1 )  ) ; ;
	__flag53__n = malloc (  ( sizeof( double ) * 17-6+1 )  ) ; ;

	/* REVISION: replace "==" with "=" TODO: correct the output of the assignment equation in SyntaxProgram */
	__flag2__n[9-6] = 0;
	__flag2__n[10-6] = 0;
	__flag2__n[11-6] = 0;
	__flag2__n[13-6] = 0;
	__flag2__n[14-6] = 0;
	__flag2__n[15-6] = 0;
	__flag2__n[16-6] = 0;
	__flag36__n[9-6] = 0;
	__flag36__n[10-6] = 0;
	__flag36__n[11-6] = 0;
	__flag36__n[13-6] = 0;
	__flag36__n[14-6] = 0;
	__flag36__n[15-6] = 0;
	__flag36__n[16-6] = 0;
	__flag49__n[9-6] = 0;
	__flag49__n[10-6] = 0;
	__flag49__n[11-6] = 0;
	__flag49__n[13-6] = 0;
	__flag49__n[14-6] = 0;
	__flag49__n[15-6] = 0;
	__flag49__n[16-6] = 0;
	__flag52__n[9-6] = 0;
	__flag52__n[10-6] = 0;
	__flag52__n[11-6] = 0;
	__flag52__n[13-6] = 0;
	__flag52__n[14-6] = 0;
	__flag52__n[15-6] = 0;
	__flag52__n[16-6] = 0;
	__flag53__n[9-6] = 0;
	__flag53__n[10-6] = 0;
	__flag53__n[11-6] = 0;
	__flag53__n[13-6] = 0;
	__flag53__n[14-6] = 0;
	__flag53__n[15-6] = 0;
	__flag53__n[16-6] = 0;
	deltat=0.001;

	/* REVISION: replace time with membrane_time TODO: homogenize the time variables */
	for(membrane_time = 0.000000; ( membrane_time <= 500.000000 ) ;membrane_time =  ( membrane_time + deltat ) ){


		/* REVISION: replace time with membrane_time and correct the indexing TODO: correct the indexing in the getSyntaxProgram */
		if(membrane_time == (double)0.000000){
			fast_sodium_current_j__n[8] = (double)0.98767124;
			fast_sodium_current_h__n[8] = (double)0.9804713;
			slow_inward_current_d__n[8] = (double)0.00316354;
			time_dependent_potassium_current_X__n[8] = (double)0.16647703;
			fast_sodium_current_m__n[8] = (double)0.00187018;
			slow_inward_current_f__n[8] = (double)0.99427859;
			membrane_V__n[8] = (double)-83.853;
			slow_inward_current_Cai__n[8] = (double)0.0002;
			fast_sodium_current_j__n[6] = (double)0.98767124;
			fast_sodium_current_h__n[6] = (double)0.9804713;
			time_dependent_potassium_current_X__n[6] = (double)0.16647703;
			slow_inward_current_d__n[6] = (double)0.00316354;
			slow_inward_current_f__n[6] = (double)0.99427859;
			fast_sodium_current_m__n[6] = (double)0.00187018;
			slow_inward_current_Cai__n[6] = (double)0.0002;
			membrane_V__n[6] = (double)-83.853;
			fast_sodium_current_h__n[7] = (double)0.9804713;
			fast_sodium_current_j__n[7] = (double)0.98767124;
			time_dependent_potassium_current_X__n[7] = (double)0.16647703;
			slow_inward_current_d__n[7] = (double)0.00316354;
			slow_inward_current_f__n[7] = (double)0.99427859;
			fast_sodium_current_m__n[7] = (double)0.00187018;
			slow_inward_current_Cai__n[7] = (double)0.0002;
			membrane_V__n[7] = (double)-83.853;
			fast_sodium_current_h__n[17] = (double)0.9804713;
			fast_sodium_current_j__n[17] = (double)0.98767124;
			fast_sodium_current_m__n[17] = (double)0.00187018;
			slow_inward_current_f__n[17] = (double)0.99427859;
			slow_inward_current_d__n[17] = (double)0.00316354;
			time_dependent_potassium_current_X__n[17] = (double)0.16647703;
			fast_sodium_current_j__n[12] = (double)0.98767124;
			fast_sodium_current_h__n[12] = (double)0.9804713;
			membrane_V__n[17] = (double)-83.853;
			slow_inward_current_Cai__n[17] = (double)0.0002;
			fast_sodium_current_m__n[12] = (double)0.00187018;
			slow_inward_current_f__n[12] = (double)0.99427859;
			slow_inward_current_d__n[12] = (double)0.00316354;
			time_dependent_potassium_current_X__n[12] = (double)0.16647703;
			membrane_V__n[12] = (double)-83.853;
			slow_inward_current_Cai__n[12] = (double)0.0002;
		}

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

		/*
		 *初期化されていない変数をとりあえず初期化しておきます
		 */
		background_current_g_b=1.0;
		background_current_E_b=1.0;
		time_dependent_potassium_current_g_Kbar=1.0;
		time_independent_potassium_current_Ko=1.0;
		membrane_R=1.0;
		membrane_T=1.0;
		time_independent_potassium_current_Ki=1.0;
		time_dependent_potassium_current_PR_NaK=1.0;
		membrane_F=1.0;
		time_dependent_potassium_current_Nai=1.0;
		time_dependent_potassium_current_Nao=1.0;
		fast_sodium_current_g_Na=1.0;
		plateau_potassium_current_g_Kp=1.0;
		membrane_C=1.0;
		deltax1=1.0;
		deltax2=1.0;
		membrane_D=1.0;



		int calcindex=(18-6)/nodenum;
		int mycalc=6+calcindex*myrank+calcindex-1;
		if((18-6)%nodenum!=0 && myrank==nodenum) mycalc+=(18-6)%nodenum;
		if(calcindex==0) {
			printf("ノード数が多すぎ今のところ対応していません");
			return -1;
		}
		for(__i=6+calcindex*myrank;__i<mycalc;__i++){

		//for(__i=6; __i<=17; __i++){
			slow_inward_current_f_gate_beta_f__n[__i] =  (  (  (  ( (double)0.0065 * exp(  (  ( - (double)0.02 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.2 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( slow_inward_current_f_gate_beta_f__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			plateau_potassium_current_Kp__n[__i] =  (  (  ( (double)1 /  ( (double)1 + exp(  (  ( (double)7.488 - membrane_V__n[__i] )  / (double)5.98 )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( plateau_potassium_current_Kp__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			slow_inward_current_f_gate_alpha_f__n[__i] =  (  (  (  ( (double)0.012 * exp(  (  ( - (double)0.008 )  *  ( membrane_V__n[__i] + (double)28 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.15 *  ( membrane_V__n[__i] + (double)28 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			slow_inward_current_d_gate_alpha_d__n[__i] =  (  (  (  ( (double)0.095 * exp(  (  ( - (double)0.01 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.072 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			slow_inward_current_d_gate_beta_d__n[__i] =  (  (  (  ( (double)0.07 * exp(  (  ( - (double)0.017 )  *  ( membrane_V__n[__i] + (double)44 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.05 *  ( membrane_V__n[__i] + (double)44 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( slow_inward_current_d_gate_beta_d__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			slow_inward_current_E_si__n[__i] =  (  (  ( (double)7.7 -  ( (double)13.0287 * log(  ( slow_inward_current_Cai__n[__i] / (double)1 )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( slow_inward_current_E_si__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			membrane_i_b__n[__i] =  (  (  ( background_current_g_b *  ( membrane_V__n[__i] - background_current_E_b )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( membrane_i_b__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_j_gate_beta_j__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)0.1212 * exp(  (  ( - (double)0.01052 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1378 )  *  ( membrane_V__n[__i] + (double)40.14 )  )  ) )  )  :  (  ( (double)0.3 * exp(  (  ( - (double)0.0000002535 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)32 )  )  ) )  )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_j_gate_beta_j__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_dependent_potassium_current_g_K__n[__i] =  (  (  ( time_dependent_potassium_current_g_Kbar * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_dependent_potassium_current_g_K__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_dependent_potassium_current_E_K__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  (  ( time_independent_potassium_current_Ko +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nao )  )  /  ( time_independent_potassium_current_Ki +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nai )  )  )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_dependent_potassium_current_E_K__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_dependent_potassium_current_X_gate_alpha_X__n[__i] =  (  (  (  ( (double)0.0005 * exp(  ( (double)0.083 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.057 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_dependent_potassium_current_X_gate_beta_X__n[__i] =  (  (  (  ( (double)0.0013 * exp(  (  ( - (double)0.06 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.04 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_dependent_potassium_current_Xi__n[__i] =  (  (  (  ( membrane_V__n[__i] >  ( - (double)100 )  )  ?  (  ( (double)2.837 *  ( exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)77 )  )  ) - (double)1 )  )  /  (  ( membrane_V__n[__i] + (double)77 )  * exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)35 )  )  ) )  )  : (double)1 )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_dependent_potassium_current_Xi__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_independent_potassium_current_g_K1__n[__i] =  (  (  ( (double)0.6047 * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_independent_potassium_current_g_K1__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			time_independent_potassium_current_E_K1__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_independent_potassium_current_Ko / time_independent_potassium_current_Ki )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( time_independent_potassium_current_E_K1__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_E_Na__n[__i] =  (  (  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_dependent_potassium_current_Nao / time_dependent_potassium_current_Nai )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_E_Na__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_j_gate_alpha_j__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  (  (  (  ( - (double)127140 )  * exp(  ( (double)0.2444 * membrane_V__n[__i] )  ) )  -  ( (double)0.00003474 * exp(  (  ( - (double)0.04391 )  * membrane_V__n[__i] )  ) )  )  *  ( membrane_V__n[__i] + (double)37.78 )  )  /  ( (double)1 + exp(  ( (double)0.311 *  ( membrane_V__n[__i] + (double)79.23 )  )  ) )  )  : (double)0 )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_h_gate_alpha_h__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  ( (double)0.135 * exp(  (  ( (double)80 + membrane_V__n[__i] )  /  ( - (double)6.8 )  )  ) )  : (double)0 )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_m_gate_beta_m__n[__i] =  (  (  ( (double)0.08 * exp(  (  ( - membrane_V__n[__i] )  / (double)11 )  ) )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_m_gate_beta_m__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_m_gate_alpha_m__n[__i] =  (  (  (  ( (double)0.32 *  ( membrane_V__n[__i] + (double)47.13 )  )  /  ( (double)1 - exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)47.13 )  )  ) )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
			fast_sodium_current_h_gate_beta_h__n[__i] =  (  (  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)3.56 * exp(  ( (double)0.079 * membrane_V__n[__i] )  ) )  +  ( (double)310000 * exp(  ( (double)0.35 * membrane_V__n[__i] )  ) )  )  :  ( (double)1 /  ( (double)0.13 *  ( (double)1 + exp(  (  ( membrane_V__n[__i] + (double)10.66 )  /  ( - (double)11.1 )  )  ) )  )  )  )  * __flag2__n[ ( __i - 6 ) ] )  +  ( fast_sodium_current_h_gate_beta_h__n[__i] *  ( 1 - __flag2__n[ ( __i - 6 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
			//X0end = X0end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//---------------------------- LOOP ----------------------------//
		for(__i=1; __i<=3; __i++){
			membrane_V__n[__i] =  ( (double)0 + membrane_V__n[ ( __i + 5 ) ] ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:5 end:5 ----------------------------//
			membrane_V__n[5] =  ( (double)0 + membrane_V__n[6] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:9 end:9 ----------------------------//
			membrane_V__n[9] =  ( (double)0 + membrane_V__n[8] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:11 end:11 ----------------------------//
			membrane_V__n[11] =  ( (double)0 + membrane_V__n[12] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:13 end:13 ----------------------------//
			membrane_V__n[13] =  ( (double)0 + membrane_V__n[12] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:16 end:16 ----------------------------//
			membrane_V__n[16] =  ( (double)0 + membrane_V__n[17] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:18 end:18 ----------------------------//
			membrane_V__n[18] =  ( (double)0 + membrane_V__n[17] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:22 end:22 ----------------------------//
			membrane_V__n[22] =  ( (double)0 + membrane_V__n[17] ) ;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
			//X1end = X1end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
			//V0end = V0end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
			//V1end = V1end;
		//------------------------------- END -------------------------------//

		//Shortest Calculation Order:0
		//----------------------------  NO LOOP: start:null end:null ----------------------------//
			//membrane_time = membrane_time;
		//------------------------------- END -------------------------------//

		/* REVISION: added the equation with differential equations, TODO: fix LeftHandSideTransposition (remove extra term at the end of equation and change the index)*/
		//Shortest Calculation Order:1
		//---------------------------- LOOP ----------------------------//
		for(__i=6; __i<=17; __i++){
			slow_inward_current_d__n1[__i] =  ( slow_inward_current_d__n[__i] + deltat * (  (  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( (double)1 - slow_inward_current_d__n[__i] )  )  -  ( slow_inward_current_d_gate_beta_d__n[__i] * slow_inward_current_d__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			fast_sodium_current_j__n1[__i] =  (  fast_sodium_current_j__n[__i] + deltat * (  (  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( (double)1 - fast_sodium_current_j__n[__i] )  )  -  ( fast_sodium_current_j_gate_beta_j__n[__i] * fast_sodium_current_j__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			slow_inward_current_f__n1[__i] =  (  slow_inward_current_f__n[__i] + deltat * (  (  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( (double)1 - slow_inward_current_f__n[__i] )  )  -  ( slow_inward_current_f_gate_beta_f__n[__i] * slow_inward_current_f__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			time_dependent_potassium_current_X__n1[__i] =  (  time_dependent_potassium_current_X__n[__i] + deltat * (  (  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( (double)1 - time_dependent_potassium_current_X__n[__i] )  )  -  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] * time_dependent_potassium_current_X__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			fast_sodium_current_m__n1[__i] =  (  fast_sodium_current_m__n[__i] + deltat * (  (  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( (double)1 - fast_sodium_current_m__n[__i] )  )  -  ( fast_sodium_current_m_gate_beta_m__n[__i] * fast_sodium_current_m__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			fast_sodium_current_h__n1[__i] =  (  fast_sodium_current_h__n[__i] + deltat * (  (  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( (double)1 - fast_sodium_current_h__n[__i] )  )  -  ( fast_sodium_current_h_gate_beta_h__n[__i] * fast_sodium_current_h__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag36__n[ ( __i - 6 ) ] ) ;
			membrane_i_si__n[__i] =  (  (  ( (double)0.09 * slow_inward_current_d__n[__i] * slow_inward_current_f__n[__i] *  ( membrane_V__n[__i] - slow_inward_current_E_si__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] )  +  ( membrane_i_si__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			membrane_i_K__n[__i] =  (  (  ( time_dependent_potassium_current_g_K__n[__i] * time_dependent_potassium_current_X__n[__i] * time_dependent_potassium_current_Xi__n[__i] *  ( membrane_V__n[__i] - time_dependent_potassium_current_E_K__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] )  +  ( membrane_i_K__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			time_independent_potassium_current_K1_gate_beta_K1__n[__i] =  (  (  (  (  ( (double)0.49124 * exp(  ( (double)0.08032 *  (  ( membrane_V__n[__i] + (double)5.476 )  - time_independent_potassium_current_E_K1__n[__i] )  )  ) )  +  ( (double)1 * exp(  ( (double)0.06175 *  ( membrane_V__n[__i] -  ( time_independent_potassium_current_E_K1__n[__i] + (double)594.31 )  )  )  ) )  )  /  ( (double)1 + exp(  (  ( - (double)0.5143 )  *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  + (double)4.753 )  )  ) )  )  * __flag36__n[ ( __i - 6 ) ] )  +  ( time_independent_potassium_current_K1_gate_beta_K1__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			plateau_potassium_current_E_Kp__n[__i] =  (  ( time_independent_potassium_current_E_K1__n[__i] * __flag36__n[ ( __i - 6 ) ] )  +  ( plateau_potassium_current_E_Kp__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			time_independent_potassium_current_K1_gate_alpha_K1__n[__i] =  (  (  ( (double)1.02 /  ( (double)1 + exp(  ( (double)0.2385 *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  - (double)59.215 )  )  ) )  )  * __flag36__n[ ( __i - 6 ) ] )  +  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			membrane_i_Na__n[__i] =  (  (  ( fast_sodium_current_g_Na * pow( fast_sodium_current_m__n[__i] , (double)3 ) * fast_sodium_current_h__n[__i] * fast_sodium_current_j__n[__i] *  ( membrane_V__n[__i] - fast_sodium_current_E_Na__n[__i] )  )  * __flag36__n[ ( __i - 6 ) ] )  +  ( membrane_i_Na__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
			membrane_I_stim__n[__i] =  (  (  (  (  ( membrane_time >= membrane_stim_start )  &&  ( membrane_time <= membrane_stim_end )  &&  (  (  ( membrane_time - membrane_stim_start )  -  ( floor(  (  ( membrane_time - membrane_stim_start )  / membrane_stim_period )  ) * membrane_stim_period )  )  <= membrane_stim_duration )  )  ? membrane_stim_amplitude : (double)0 )  * __flag36__n[ ( __i - 6 ) ] )  +  ( membrane_I_stim__n[__i] *  ( 1 - __flag36__n[ ( __i - 6 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: added the equation with differential equations, TODO: fix LeftHandSideTransposition (remove extra term at the end of equation and change the index)*/
		//Shortest Calculation Order:2
		//---------------------------- LOOP ----------------------------//
		for(__i=6; __i<=17; __i++){
			slow_inward_current_Cai__n1[__i] = ( slow_inward_current_Cai__n[__i] + deltat * (  (  (  (  ( - (double)0.0001 )  / (double)1 )  * membrane_i_si__n[__i] )  +  ( (double)0.07 *  ( (double)0.0001 - slow_inward_current_Cai__n[__i] )  )  )  * __flag49__n[ ( __i - 6 ) ] ) ) *  ( 1 - __flag49__n[ ( __i - 6 ) ] ) ;
			membrane_i_Kp__n[__i] =  (  (  ( plateau_potassium_current_g_Kp * plateau_potassium_current_Kp__n[__i] *  ( membrane_V__n[__i] - plateau_potassium_current_E_Kp__n[__i] )  )  * __flag49__n[ ( __i - 6 ) ] )  +  ( membrane_i_Kp__n[__i] *  ( 1 - __flag49__n[ ( __i - 6 ) ] )  )  ) ;
			time_independent_potassium_current_K1_infinity__n[__i] =  (  (  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] /  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] + time_independent_potassium_current_K1_gate_beta_K1__n[__i] )  )  * __flag49__n[ ( __i - 6 ) ] )  +  ( time_independent_potassium_current_K1_infinity__n[__i] *  ( 1 - __flag49__n[ ( __i - 6 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		//Shortest Calculation Order:3
		//---------------------------- LOOP ----------------------------//
		for(__i=6; __i<=17; __i++){
			membrane_i_K1__n[__i] =  (  (  ( time_independent_potassium_current_g_K1__n[__i] * time_independent_potassium_current_K1_infinity__n[__i] *  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  )  * __flag52__n[ ( __i - 6 ) ] )  +  ( membrane_i_K1__n[__i] *  ( 1 - __flag52__n[ ( __i - 6 ) ] )  )  ) ;
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: added the equation with differential equations, TODO: fix LeftHandSideTransposition (remove extra term at the end of equation). FIX indexing */
		//Shortest Calculation Order:4
		//---------------------------- LOOP ----------------------------//
		for(__i=6; __i<=17; __i++){
			membrane_V__n1[__i]  =  ( membrane_V__n[__i] + deltat * (  (  (  (  ( - (double)1 )  / membrane_C )  *  ( membrane_I_stim__n[__i] + membrane_i_Na__n[__i] + membrane_i_si__n[__i] + membrane_i_K__n[__i] + membrane_i_K1__n[__i] + membrane_i_Kp__n[__i] + membrane_i_b__n[__i] )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( __i + 1 ) ] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[__i-1] )  /  ( deltax1 * deltax1 )  )  )  +  ( membrane_D *  (  ( membrane_V__n[__i+5] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[__i-5] )  /  ( deltax2 * deltax2 )  )  )  )  * __flag53__n[ ( __i - 6 ) ] ) )  *  ( 1 - __flag53__n[ ( __i - 6 ) ] );
		}
		//----------------------------- LOOP END -----------------------------//

		/* REVISION: reassign the results of index n1(n+1) to index n TODO: harmonize with structured relml version */
		for(__i=6; __i<=17; __i++){
			fast_sodium_current_j__n[__i] = fast_sodium_current_j__n1[__i];
			fast_sodium_current_h__n[__i] = fast_sodium_current_h__n1[__i];
			slow_inward_current_d__n[__i] = slow_inward_current_d__n1[__i];
			time_dependent_potassium_current_X__n[__i] = time_dependent_potassium_current_X__n1[__i];
			fast_sodium_current_m__n[__i] = fast_sodium_current_m__n1[__i];
			slow_inward_current_f__n[__i] = slow_inward_current_f__n1[__i];
			membrane_V__n[__i] = membrane_V__n1[__i];
		}

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
	free ( membrane_I_stim__n ) ;
	free ( membrane_V__n ) ;
	free ( membrane_V__n1 ) ;
	free ( membrane_i_K1__n ) ;
	free ( membrane_i_K__n ) ;
	free ( membrane_i_Kp__n ) ;
	free ( membrane_i_Na__n ) ;
	free ( membrane_i_b__n ) ;
	free ( membrane_i_si__n ) ;
	/* REVISION: remove free( membrane_time, i and n )*/
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
	free ( __flag36__n ) ;
	free ( __flag49__n ) ;
	free ( __flag52__n ) ;
	free ( __flag53__n ) ;
	return 0;
}




