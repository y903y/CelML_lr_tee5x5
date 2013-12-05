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
#define __MAX_DATA_NUM 626
#define __MAX_MATERIAL_NUM 518


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
	calcindex = __MAX_MATERIAL_NUM/nodenum;
	mycalc = ((calcindex * myrank) + calcindex) - 1;
	if(__MAX_MATERIAL_NUM % nodenum != 0 && myrank == nodenum - 1) mycalc += __MAX_MATERIAL_NUM % nodenum;
	if(calcindex == 0) {
		printf("ノード数が多すぎ今のところ対応していません\n");
		return -1;
	}
	sourcebuf = calcindex * myrank;

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
	int __i;

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

	/* REVISION: declare the list of neighbors left (L), right (R), up (U) and down (D) for each node. non-existent neighbors are assigned as -1 */
	int L[__MAX_DATA_NUM] = {527, 0, 1, 2, 3, 4, 531, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 534, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 536, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 538, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 540, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 542, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 544, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 546, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 548, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 550, 166, 167, 168, 169, 170, 171, 172, 173, 174, 554, 176, 177, 178, 179, 180, 181, 182, 183, 184, 556, 186, 187, 188, 189, 190, 191, 192, 193, 194, 558, 196, 197, 198, 199, 200, 201, 202, 203, 204, 560, 206, 207, 208, 209, 210, 211, 212, 213, 562, 215, 216, 217, 218, 219, 220, 221, 222, 564, 224, 225, 226, 227, 228, 229, 230, 231, 566, 233, 234, 235, 236, 237, 238, 239, 240, 568, 242, 243, 244, 245, 246, 247, 248, 570, 250, 251, 252, 253, 254, 255, 256, 572, 258, 259, 260, 261, 262, 263, 264, 574, 266, 267, 268, 269, 270, 271, 272, 576, 274, 275, 276, 277, 278, 279, 280, 281, 578, 283, 284, 285, 286, 287, 288, 289, 290, 580, 292, 293, 294, 295, 296, 297, 298, 299, 582, 301, 302, 303, 304, 305, 306, 307, 308, 584, 310, 311, 312, 313, 314, 315, 316, 317, 318, 586, 320, 321, 322, 323, 324, 325, 326, 327, 328, 588, 330, 331, 332, 333, 334, 335, 336, 337, 338, 592, 340, 341, 342, 343, 344, 345, 346, 347, 348, 594, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 596, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 598, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 600, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 602, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 604, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 606, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 608, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 611, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 615, 510, 511, 512, 513, 514, 515, 516, -1, 518, 519, 520, 521, 522, -1, 524, 525, 526, 5, 528, -1, 530, 17, 532, -1, 33, -1, 51, -1, 71, -1, 93, -1, 117, -1, 141, -1, 153, 547, 165, -1, 175, 551, -1, 553, 185, -1, 195, -1, 205, 559, 214, -1, 223, 563, 232, -1, 241, 567, 249, -1, 257, 571, 265, -1, 273, 575, 282, -1, 291, 579, 300, -1, 309, 583, 319, -1, 329, -1, 339, 589, -1, 591, 349, -1, 361, 595, 373, -1, 397, -1, 421, -1, 443, -1, 463, -1, 481, -1, 497, -1, 610, 509, 612, -1, 614, 517, 616, -1, 618, 619, 620, 621, 622, 623, 624};
	int R[__MAX_DATA_NUM] = {  1, 2, 3, 4, 5, 528, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 532, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 535, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 537, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 539, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 541, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 543, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 545, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 547, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 549, 167, 168, 169, 170, 171, 172, 173, 174, 175, 551, 177, 178, 179, 180, 181, 182, 183, 184, 185, 555, 187, 188, 189, 190, 191, 192, 193, 194, 195, 557, 197, 198, 199, 200, 201, 202, 203, 204, 205, 559, 207, 208, 209, 210, 211, 212, 213, 214, 561, 216, 217, 218, 219, 220, 221, 222, 223, 563, 225, 226, 227, 228, 229, 230, 231, 232, 565, 234, 235, 236, 237, 238, 239, 240, 241, 567, 243, 244, 245, 246, 247, 248, 249, 569, 251, 252, 253, 254, 255, 256, 257, 571, 259, 260, 261, 262, 263, 264, 265, 573, 267, 268, 269, 270, 271, 272, 273, 575, 275, 276, 277, 278, 279, 280, 281, 282, 577, 284, 285, 286, 287, 288, 289, 290, 291, 579, 293, 294, 295, 296, 297, 298, 299, 300, 581, 302, 303, 304, 305, 306, 307, 308, 309, 583, 311, 312, 313, 314, 315, 316, 317, 318, 319, 585, 321, 322, 323, 324, 325, 326, 327, 328, 329, 587, 331, 332, 333, 334, 335, 336, 337, 338, 339, 589, 341, 342, 343, 344, 345, 346, 347, 348, 349, 593, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 595, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 597, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 599, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 601, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 603, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 605, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 607, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 609, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 612, 511, 512, 513, 514, 515, 516, 517, 616, 519, 520, 521, 522, 523, -1, 525, 526, 527, 0, 529, -1, 531, 6, 533, -1, 18, -1, 34, -1, 52, -1, 72, -1, 94, -1, 118, -1, 142, 548, 154, -1, 166, 552, -1, 554, 176, -1, 186, -1, 196, 560, 206, -1, 215, 564, 224, -1, 233, 568, 242, -1, 250, 572, 258, -1, 266, 576, 274, -1, 283, 580, 292, -1, 301, 584, 310, -1, 320, -1, 330, 590, -1, 592, 340, -1, 350, 596, 362, -1, 374, -1, 398, -1, 422, -1, 444, -1, 464, -1, 482, -1, 611, 498, 613, -1, 615, 510, 617, -1, 619, 620, 621, 622, 623, 624, 625, -1};
	int U[__MAX_DATA_NUM] = {518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 0, 1, 2, 3, 4, 5, 528, 529, 530, 531, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 532, 533, 534, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 535, 536, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 537, 538, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 539, 540, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 541, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 544, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 545, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 550, 166, 167, 168, 169, 170, 171, 172, 173, 174, 177, 178, 179, 180, 181, 182, 183, 184, 185, 555, 186, 187, 188, 189, 190, 191, 192, 193, 194, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 573, 574, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 581, 582, 301, 302, 303, 304, 305, 306, 307, 308, 309, 311, 312, 313, 314, 315, 316, 317, 318, 319, 585, 586, 320, 321, 322, 323, 324, 325, 326, 327, 328, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 589, 590, 591, 592, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 595, 596, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 500, 501, 502, 503, 504, 505, 506, 507, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 542, 543, -1, 129, 130, -1, 546, 152, 153, 154, 155, 549, -1, 175, 176, -1, 556, 195, 196, 559, 560, 561, 562, 563, 564, 232, 233, 567, 568, 569, 570, 571, 572, -1, -1, 575, 576, 577, 578, 579, 580, -1, -1, 583, 310, -1, -1, -1, -1, 329, 588, -1, -1, 593, 350, 373, 598, 599, 398, 421, 422, 443, 444, 463, 464, 481, 482, 483, 496, 497, 498, 499, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517};
	int D[__MAX_DATA_NUM] = { 10, 11, 12, 13, 14, 15, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 547, 548, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 551, 552, 553, 554, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 187, 188, 189, 190, 191, 192, 193, 194, 195, 557, 558, 196, 197, 198, 199, 200, 201, 202, 203, 204, 206, 207, 208, 209, 210, 211, 212, 213, 214, 561, 562, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 569, 570, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 321, 322, 323, 324, 325, 326, 327, 328, 329, 588, 330, 331, 332, 333, 334, 335, 336, 337, 338, 341, 342, 343, 344, 345, 346, 347, 348, 349, 593, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 598, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 599, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 602, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 603, 604, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 605, 606, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 607, 608, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 609, 610, 611, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 612, 613, 614, 615, 510, 511, 512, 513, 514, 515, 516, 517, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 16, 17, 18, 19, 32, 33, 34, 51, 52, 71, 72, 93, 94, 117, 544, 545, 142, 165, 550, -1, -1, 555, 186, -1, -1, -1, -1, 205, 560, -1, -1, 563, 564, 565, 566, 567, 568, -1, -1, 571, 572, 573, 574, 575, 576, 282, 283, 579, 580, 581, 582, 583, 584, 319, 320, 587, -1, 339, 340, -1, 594, 360, 361, 362, 363, 597, -1, 385, 386, -1, 600, 601, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	/*Revision*/
	for(membrane_time = 0.000000; ( membrane_time <= 500.000000 ) ;membrane_time =  ( membrane_time + deltat ) ){

		/*演算範囲の変更*/
		if(timeCount % 2 == 0){
			if(mycalc != __MAX_MATERIAL_NUM - 1) mycalc = D[mycalc];
			if(sourcebuf != 0) sourcebuf = U[sourcebuf];
		}

		/* REVISION: correct the indexing TODO: put the correct range of morphology nodes */
		for(__i = sourcebuf; __i <= mycalc; __i++){
			slow_inward_current_f_gate_beta_f__n[__i] =  (  ( (double)0.0065 * exp(  (  ( - (double)0.02 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.2 )  *  ( membrane_V__n[__i] + (double)30 )  )  ) )  ) ;
			plateau_potassium_current_Kp__n[__i] =  ( (double)1 /  ( (double)1 + exp(  (  ( (double)7.488 - membrane_V__n[__i] )  / (double)5.98 )  ) )  );
			slow_inward_current_f_gate_alpha_f__n[__i] =  (  ( (double)0.012 * exp(  (  ( - (double)0.008 )  *  ( membrane_V__n[__i] + (double)28 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.15 *  ( membrane_V__n[__i] + (double)28 )  )  ) )  ) ;
			slow_inward_current_d_gate_alpha_d__n[__i] =  (  ( (double)0.095 * exp(  (  ( - (double)0.01 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.072 )  *  ( membrane_V__n[__i] - (double)5 )  )  ) )  ) ;
			slow_inward_current_d_gate_beta_d__n[__i] =  (  ( (double)0.07 * exp(  (  ( - (double)0.017 )  *  ( membrane_V__n[__i] + (double)44 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.05 *  ( membrane_V__n[__i] + (double)44 )  )  ) )  ) ;
			slow_inward_current_E_si__n[__i] =  ( (double)7.7 -  ( (double)13.0287 * log(  ( slow_inward_current_Cai__n[__i] / (double)1 )  ) )  ) ;
			membrane_i_b__n[__i] =  ( background_current_g_b *  ( membrane_V__n[__i] - background_current_E_b )  ) ;
			fast_sodium_current_j_gate_beta_j__n[__i] =  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)0.1212 * exp(  (  ( - (double)0.01052 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1378 )  *  ( membrane_V__n[__i] + (double)40.14 )  )  ) )  )  :  (  ( (double)0.3 * exp(  (  ( - (double)0.0000002535 )  * membrane_V__n[__i] )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)32 )  )  ) )  )  ) ;
			time_dependent_potassium_current_g_K__n[__i] =  ( time_dependent_potassium_current_g_Kbar * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) ) ;
			time_dependent_potassium_current_E_K__n[__i] =  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  (  ( time_independent_potassium_current_Ko +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nao )  )  /  ( time_independent_potassium_current_Ki +  ( time_dependent_potassium_current_PR_NaK * time_dependent_potassium_current_Nai )  )  )  ) ) ;
			time_dependent_potassium_current_X_gate_alpha_X__n[__i] =  (  ( (double)0.0005 * exp(  ( (double)0.083 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  /  ( (double)1 + exp(  ( (double)0.057 *  ( membrane_V__n[__i] + (double)50 )  )  ) )  ) ;
			time_dependent_potassium_current_X_gate_beta_X__n[__i] =  (  ( (double)0.0013 * exp(  (  ( - (double)0.06 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  /  ( (double)1 + exp(  (  ( - (double)0.04 )  *  ( membrane_V__n[__i] + (double)20 )  )  ) )  ) ;
			time_dependent_potassium_current_Xi__n[__i] =  (  ( membrane_V__n[__i] >  ( - (double)100 )  )  ?  (  ( (double)2.837 *  ( exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)77 )  )  ) - (double)1 )  )  /  (  ( membrane_V__n[__i] + (double)77 )  * exp(  ( (double)0.04 *  ( membrane_V__n[__i] + (double)35 )  )  ) )  )  : (double)1 ) ;
			time_independent_potassium_current_g_K1__n[__i] =  ( (double)0.6047 * sqrt(  ( time_independent_potassium_current_Ko / (double)5.4 )  ) ) ;
			time_independent_potassium_current_E_K1__n[__i] =  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_independent_potassium_current_Ko / time_independent_potassium_current_Ki )  ) ) ;
			fast_sodium_current_E_Na__n[__i] =  (  (  ( membrane_R * membrane_T )  / membrane_F )  * log(  ( time_dependent_potassium_current_Nao / time_dependent_potassium_current_Nai )  ) ) ;
			fast_sodium_current_j_gate_alpha_j__n[__i] =  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  (  (  (  ( - (double)127140 )  * exp(  ( (double)0.2444 * membrane_V__n[__i] )  ) )  -  ( (double)0.00003474 * exp(  (  ( - (double)0.04391 )  * membrane_V__n[__i] )  ) )  )  *  ( membrane_V__n[__i] + (double)37.78 )  )  /  ( (double)1 + exp(  ( (double)0.311 *  ( membrane_V__n[__i] + (double)79.23 )  )  ) )  )  : (double)0 ) ;
			fast_sodium_current_h_gate_alpha_h__n[__i] =  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  ( (double)0.135 * exp(  (  ( (double)80 + membrane_V__n[__i] )  /  ( - (double)6.8 )  )  ) )  : (double)0 ) ;
			fast_sodium_current_m_gate_beta_m__n[__i] =  ( (double)0.08 * exp(  (  ( - membrane_V__n[__i] )  / (double)11 )  ) ) ;
			fast_sodium_current_m_gate_alpha_m__n[__i] =  (  ( (double)0.32 *  ( membrane_V__n[__i] + (double)47.13 )  )  /  ( (double)1 - exp(  (  ( - (double)0.1 )  *  ( membrane_V__n[__i] + (double)47.13 )  )  ) )  ) ;
			fast_sodium_current_h_gate_beta_h__n[__i] =  (  ( membrane_V__n[__i] <  ( - (double)40 )  )  ?  (  ( (double)3.56 * exp(  ( (double)0.079 * membrane_V__n[__i] )  ) )  +  ( (double)310000 * exp(  ( (double)0.35 * membrane_V__n[__i] )  ) )  )  :  ( (double)1 /  ( (double)0.13 *  ( (double)1 + exp(  (  ( membrane_V__n[__i] + (double)10.66 )  /  ( - (double)11.1 )  )  ) )  )  )  ) ;
		}

		/*MPI_Send,Recvを用いた双方向通信*/
		if(timeCount % 2 == 1) {
			if(myrank == root) {
				//st = MPI_Wtime();
				MPI_Send(&membrane_V__n[82], 47, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
				MPI_Recv(&membrane_V__n[129], 47, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, &recv_status);
				//en = MPI_Wtime();
			} else if (myrank ==1){
				MPI_Recv(&membrane_V__n[82], 47, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &recv_status);
				MPI_Send(&membrane_V__n[224], 34, MPI_DOUBLE, 2, tag, MPI_COMM_WORLD);
				MPI_Recv(&membrane_V__n[258], 34, MPI_DOUBLE, 2, tag, MPI_COMM_WORLD, &recv_status);
				MPI_Send(&membrane_V__n[129], 47, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
			} else if (myrank == 2) {
				MPI_Recv(&membrane_V__n[224], 34, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, &recv_status);
				MPI_Send(&membrane_V__n[340], 47, MPI_DOUBLE, 3, tag, MPI_COMM_WORLD);
				MPI_Recv(&membrane_V__n[387], 47, MPI_DOUBLE, 3, tag, MPI_COMM_WORLD, &recv_status);
				MPI_Send(&membrane_V__n[258], 34, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
			} else if (myrank == nodenum-1){
				MPI_Recv(&membrane_V__n[340], 47, MPI_DOUBLE, 2, tag, MPI_COMM_WORLD, &recv_status);
				MPI_Send(&membrane_V__n[387], 47, MPI_DOUBLE, 2, tag, MPI_COMM_WORLD);
			}
		}

		/* REVISION: correct the boundary condition equations (remove unneccessary flags) */
		//---------------------------- NODE 13 - 206 D[] ----------------------------//
		for(__i=518; __i<=541; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 242 - 267 D[] ----------------------------//
		for(__i=544; __i<=545; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 301 D[] ----------------------------//
			membrane_V__n[550] =  membrane_V__n[D[550]] ;
		//---------------------------- NODE 328 D[] ----------------------------//
			membrane_V__n[555] =  membrane_V__n[D[555]] ;
		//---------------------------- NODE 459 - 470 D[] ----------------------------//
		for(__i=573; __i<=574; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 520 - 529 D[] ----------------------------//
		for(__i=581; __i<=582; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 551 - 558 D[] ----------------------------//
		for(__i=585; __i<=586; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 582 - 587 D[] ----------------------------//
		for(__i=589; __i<=592; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( D[__i] ) ] ;
		}
		//---------------------------- NODE 614 - 615 D[] ----------------------------//
		for(__i=595; __i<=596; __i++){
			membrane_V__n[__i] =  membrane_V__n[ ( D[__i] ) ] ;
		}

		//---------------------------- NODE 212 R[] ----------------------------//
			membrane_V__n[542] =  membrane_V__n[R[542]] ;
		//---------------------------- NODE 271 R[] ----------------------------//
			membrane_V__n[546] =  membrane_V__n[R[546]] ;
		//---------------------------- NODE 330 R[] ----------------------------//
			membrane_V__n[556] =  membrane_V__n[R[556]] ;
		//---------------------------- NODE 360 R[] ----------------------------//
			membrane_V__n[560] =  membrane_V__n[R[560]] ;
		//---------------------------- NODE 390 R[] ----------------------------//
			membrane_V__n[564] =  membrane_V__n[R[564]] ;
		//---------------------------- NODE 409 R[] ----------------------------//
			membrane_V__n[566] =  membrane_V__n[R[566]] ;
		//---------------------------- NODE 420 R[] ----------------------------//
			membrane_V__n[568] =  membrane_V__n[R[568]] ;
		//---------------------------- NODE 450 R[] ----------------------------//
			membrane_V__n[572] =  membrane_V__n[R[572]] ;
		//---------------------------- NODE 480 R[] ----------------------------//
			membrane_V__n[576] =  membrane_V__n[R[576]] ;
		//---------------------------- NODE 499 R[]----------------------------//
			membrane_V__n[578] =  membrane_V__n[R[578]] ;
		//---------------------------- NODE 510 R[] ----------------------------//
			membrane_V__n[580] =  membrane_V__n[R[580]] ;
		//---------------------------- NODE 540 R[]----------------------------//
			membrane_V__n[584] =  membrane_V__n[R[584]] ;
		//---------------------------- NODE 601 R[] ----------------------------//
			membrane_V__n[594] =  membrane_V__n[R[594]] ;
		//---------------------------- NODE 662 R[] ----------------------------//
			membrane_V__n[600] =  membrane_V__n[R[600]] ;

		//---------------------------- NODE 237 L[] ----------------------------//
			membrane_V__n[543] =  membrane_V__n[L[543]] ;
		//---------------------------- NODE 298 L[] ----------------------------//
			membrane_V__n[549] =  membrane_V__n[L[549]] ;
		//---------------------------- NODE 359 L[] ----------------------------//
			membrane_V__n[559] =  membrane_V__n[L[559]] ;
		//---------------------------- NODE 389 L[] ----------------------------//
			membrane_V__n[563] =  membrane_V__n[L[563]] ;
		//---------------------------- NODE 400 L[] ----------------------------//
			membrane_V__n[565] =  membrane_V__n[L[565]] ;
		//---------------------------- NODE 419 L[] ----------------------------//
			membrane_V__n[567] =  membrane_V__n[L[567]] ;
		//---------------------------- NODE 449 L[] ----------------------------//
			membrane_V__n[571] =  membrane_V__n[L[571]] ;
		//---------------------------- NODE 479 L[] ----------------------------//
			membrane_V__n[575] =  membrane_V__n[L[575]] ;
		//---------------------------- NODE 490 L[] ----------------------------//
			membrane_V__n[577] =  membrane_V__n[L[577]] ;
		//---------------------------- NODE 509 L[] ----------------------------//
			membrane_V__n[579] =  membrane_V__n[L[579]] ;
		//---------------------------- NODE 539 L[] ----------------------------//
			membrane_V__n[583] =  membrane_V__n[L[583]] ;
		//---------------------------- NODE 569 L[] ----------------------------//
			membrane_V__n[587] =  membrane_V__n[L[587]] ;
		//---------------------------- NODE 628 L[] ----------------------------//
			membrane_V__n[597] =  membrane_V__n[L[597]] ;
		//---------------------------- NODE 687 L[] ----------------------------//
			membrane_V__n[601] =  membrane_V__n[L[601]] ;

		//---------------------------- NODE 284 - 285 U[] ----------------------------//
		for(__i=547; __i<=548; __i++){
			membrane_V__n[__i] =  membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 312 - 317 U[] ----------------------------//
		for(__i=551; __i<=554; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 341 - 348 U[] ----------------------------//
		for(__i=557; __i<=558; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 370 - 379 U[] ----------------------------//
		for(__i=561; __i<=562; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 429-440 U[] ----------------------------//
		for(__i=569; __i<=570; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 571 U[] ----------------------------//
			membrane_V__n[588] =  membrane_V__n[U[588]] ;
		//---------------------------- NODE 598 U[] ----------------------------//
			membrane_V__n[593] =  membrane_V__n[U[593]] ;
		//---------------------------- NODE 632 - 657 U[] ----------------------------//
		for(__i=598; __i<=599; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}
		//---------------------------- NODE 693 - 888 U[] ----------------------------//
		for(__i=602; __i<=625; __i++){
			membrane_V__n[__i] = membrane_V__n[ ( U[__i] ) ] ;
		}

		/* REVISION: added the equation with differential equations TODO: revise the stimulation equation */
		//Shortest Calculation Order:1
		for(__i = sourcebuf; __i <= mycalc; __i++){
			slow_inward_current_d__n1[__i] =  ( slow_inward_current_d__n[__i] + deltat * (  ( slow_inward_current_d_gate_alpha_d__n[__i] *  ( (double)1 - slow_inward_current_d__n[__i] )  )  -  ( slow_inward_current_d_gate_beta_d__n[__i] * slow_inward_current_d__n[__i] )  ) ) ;
			fast_sodium_current_j__n1[__i] =  ( fast_sodium_current_j__n[__i] + deltat * (  ( fast_sodium_current_j_gate_alpha_j__n[__i] *  ( (double)1 - fast_sodium_current_j__n[__i] )  )  -  ( fast_sodium_current_j_gate_beta_j__n[__i] * fast_sodium_current_j__n[__i] )  ) ) ;
			slow_inward_current_f__n1[__i] =  ( slow_inward_current_f__n[__i] + deltat * (  ( slow_inward_current_f_gate_alpha_f__n[__i] *  ( (double)1 - slow_inward_current_f__n[__i] )  )  -  ( slow_inward_current_f_gate_beta_f__n[__i] * slow_inward_current_f__n[__i] )  ) ) ;
			time_dependent_potassium_current_X__n1[__i] =  ( time_dependent_potassium_current_X__n[__i] + deltat * (  ( time_dependent_potassium_current_X_gate_alpha_X__n[__i] *  ( (double)1 - time_dependent_potassium_current_X__n[__i] )  )  -  ( time_dependent_potassium_current_X_gate_beta_X__n[__i] * time_dependent_potassium_current_X__n[__i] )  ) ) ;
			fast_sodium_current_m__n1[__i] =  ( fast_sodium_current_m__n[__i] + deltat * (  ( fast_sodium_current_m_gate_alpha_m__n[__i] *  ( (double)1 - fast_sodium_current_m__n[__i] )  )  -  ( fast_sodium_current_m_gate_beta_m__n[__i] * fast_sodium_current_m__n[__i] )  ) ) ;
			fast_sodium_current_h__n1[__i] =  ( fast_sodium_current_h__n[__i] + deltat * (  ( fast_sodium_current_h_gate_alpha_h__n[__i] *  ( (double)1 - fast_sodium_current_h__n[__i] )  )  -  ( fast_sodium_current_h_gate_beta_h__n[__i] * fast_sodium_current_h__n[__i] )  ) ) ;
			membrane_i_si__n[__i] =  ( (double)0.09 * slow_inward_current_d__n[__i] * slow_inward_current_f__n[__i] *  ( membrane_V__n[__i] - slow_inward_current_E_si__n[__i] )  ) ;
			membrane_i_K__n[__i] =  ( time_dependent_potassium_current_g_K__n[__i] * time_dependent_potassium_current_X__n[__i] * time_dependent_potassium_current_Xi__n[__i] *  ( membrane_V__n[__i] - time_dependent_potassium_current_E_K__n[__i] )  ) ;
			time_independent_potassium_current_K1_gate_beta_K1__n[__i] =  (  (  ( (double)0.49124 * exp(  ( (double)0.08032 *  (  ( membrane_V__n[__i] + (double)5.476 )  - time_independent_potassium_current_E_K1__n[__i] )  )  ) )  +  ( (double)1 * exp(  ( (double)0.06175 *  ( membrane_V__n[__i] -  ( time_independent_potassium_current_E_K1__n[__i] + (double)594.31 )  )  )  ) )  )  /  ( (double)1 + exp(  (  ( - (double)0.5143 )  *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  + (double)4.753 )  )  ) )  ) ;
			plateau_potassium_current_E_Kp__n[__i] =  time_independent_potassium_current_E_K1__n[__i] ;
			time_independent_potassium_current_K1_gate_alpha_K1__n[__i] =  ( (double)1.02 /  ( (double)1 + exp(  ( (double)0.2385 *  (  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  - (double)59.215 )  )  ) )  ) ;
			membrane_i_Na__n[__i] =  ( fast_sodium_current_g_Na * pow( fast_sodium_current_m__n[__i] , (double)3 ) * fast_sodium_current_h__n[__i] * fast_sodium_current_j__n[__i] *  ( membrane_V__n[__i] - fast_sodium_current_E_Na__n[__i] )  ) ;
			/* REVISION: revise the stimulation equations apply if else TODO: see if it can be done manually, else make Istim = 0; */
			if (__i>=0 && __i<=5) {
				membrane_I_stim__n[__i] =  (  (  ( membrane_time >= membrane_stim_start )  &&  ( membrane_time <= membrane_stim_end )  &&  (  (  ( membrane_time - membrane_stim_start )  -  ( floor(  (  ( membrane_time - membrane_stim_start )  / membrane_stim_period )  ) * membrane_stim_period )  )  <= membrane_stim_duration )  )  ? membrane_stim_amplitude : (double)0 ) ;
			} else {
				membrane_I_stim__n[__i] =  0 ;
			}

		}


		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:2
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=0; __i<__MAX_MATERIAL_NUM; __i++){
			slow_inward_current_Cai__n1[__i] = ( slow_inward_current_Cai__n[__i] + deltat * (  (  (  ( - (double)0.0001 )  / (double)1 )  * membrane_i_si__n[__i] )  +  ( (double)0.07 *  ( (double)0.0001 - slow_inward_current_Cai__n[__i] )  )  ) ) ;
			membrane_i_Kp__n[__i] =  ( plateau_potassium_current_g_Kp * plateau_potassium_current_Kp__n[__i] *  ( membrane_V__n[__i] - plateau_potassium_current_E_Kp__n[__i] )  ) ;
			time_independent_potassium_current_K1_infinity__n[__i] =  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] /  ( time_independent_potassium_current_K1_gate_alpha_K1__n[__i] + time_independent_potassium_current_K1_gate_beta_K1__n[__i] )  ) ;
		}

		//Shortest Calculation Order:3
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=0; __i<__MAX_MATERIAL_NUM; __i++){
			membrane_i_K1__n[__i] =  ( time_independent_potassium_current_g_K1__n[__i] * time_independent_potassium_current_K1_infinity__n[__i] *  ( membrane_V__n[__i] - time_independent_potassium_current_E_K1__n[__i] )  ) ;
		}


		/* REVISION: added the equation with differential equations */
		//Shortest Calculation Order:4
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=0; __i<__MAX_MATERIAL_NUM; __i++){
			membrane_V__n1[__i]  =  ( membrane_V__n[__i] + deltat * ( (  (  ( - (double)1 )  / membrane_C )  *  ( membrane_I_stim__n[__i] + membrane_i_Na__n[__i] + membrane_i_si__n[__i] + membrane_i_K__n[__i] + membrane_i_K1__n[__i] + membrane_i_Kp__n[__i] + membrane_i_b__n[__i] )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( R[__i] ) ] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[ ( L[__i] ) ] )  /  ( deltax1 * deltax1 )  )  )  +  ( membrane_D *  (  ( membrane_V__n[ ( D[__i] )] +  ( -  ( (double)2 * membrane_V__n[__i] )  )  + membrane_V__n[ ( U[__i] ) ] )  /  ( deltax2 * deltax2 )  )  )  ) ) ;
		}


		/* REVISION: print current time */
		/*if (myrank == root) {
			if (timeCount % ((int)(100)) == 0) {
				printf("%f ", membrane_time);
			}
		}*/

		/* REVISION: reassign the results of index n1(n+1) to index n TODO: harmonize with structured relml version */
		for(__i = sourcebuf; __i <= mycalc; __i++){
		//for(__i=0; __i<__MAX_MATERIAL_NUM; __i++){
			fast_sodium_current_j__n[__i] = fast_sodium_current_j__n1[__i];
			fast_sodium_current_h__n[__i] = fast_sodium_current_h__n1[__i];
			slow_inward_current_d__n[__i] = slow_inward_current_d__n1[__i];
			time_dependent_potassium_current_X__n[__i] = time_dependent_potassium_current_X__n1[__i];
			fast_sodium_current_m__n[__i] = fast_sodium_current_m__n1[__i];
			slow_inward_current_f__n[__i] = slow_inward_current_f__n1[__i];
			membrane_V__n[__i] = membrane_V__n1[__i];

			/* REVISION: print a partial part of results (opposite ends of the morphology) */
			/*if (myrank == root) {
				if (timeCount % ((int)(100)) == 0) {
					if ( __i>=0 && __i<=128) {
						printf("%f ", membrane_V__n1[__i]);
					}
					if ( __i==3 ) {
						printf(" <--- stim start : array end ---> ");
					}
					if ( __i>=515 && __i<=517) {
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

		/*演算範囲を元に戻す*/
		if(timeCount % 2 == 0){
			if(mycalc != __MAX_MATERIAL_NUM - 1) mycalc = U[mycalc];
			if(sourcebuf != 0) sourcebuf = D[sourcebuf];
		}

		/* REVISION: insert time counter */
		timeCount =  ( timeCount + 1 ) ;

	}


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

	/*MPIの終了*/
	MPI_Finalize();


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



