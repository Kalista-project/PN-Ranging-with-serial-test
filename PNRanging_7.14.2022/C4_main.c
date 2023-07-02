#include <stdio.h>
#include "PNRanging_Functions.h"

static int C4_0[] = { -5 };

int* C4(data) {
	/* Initalizing correlators arrays. These will hold the corresponding component sequences for the delay.
	They are allocated for a component sequences corresponding to a Tausworth length 4 code. */
	static int n = 0;
	static float C4_Delay0_Correlation = 0;
	static float C4_Delay1_Correlation = 0;
	static float C4_Delay2_Correlation = 0;
	static float C4_Delay3_Correlation = 0;
	static float C4_Delay4_Correlation = 0;
	static float C4_Delay5_Correlation = 0;
	static float C4_Delay6_Correlation = 0;
	static float C4_Delay7_Correlation = 0;
	static float C4_Delay8_Correlation = 0;
	static float C4_Delay9_Correlation = 0;
	static float C4_Delay10_Correlation = 0;
	static float C4_Delay11_Correlation = 0;
	static float C4_Delay12_Correlation = 0;
	static float C4_Delay13_Correlation = 0;
	static float C4_Delay14_Correlation = 0;
	static int data_tracker = 0;
	static int  C4_delay0[] = { 1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,0 };
	static int  C4_delay1[] = { 1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1 };
	static int  C4_delay2[] = { 1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,2 };
	static int  C4_delay3[] = { 1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,3 };
	static int  C4_delay4[] = { -1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,4 };
	static int  C4_delay5[] = { -1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,5 };
	static int  C4_delay6[] = { -1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,6 };
	static int  C4_delay7[] = { 1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,7 };
	static int  C4_delay8[] = { -1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,8 };
	static int  C4_delay9[] = { -1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,9 };
	static int  C4_delay10[] = { 1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,10 };
	static int  C4_delay11[] = { 1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,11 };
	static int  C4_delay12[] = { -1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,12 };
	static int  C4_delay13[] = { 1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,13 };
	static int  C4_delay14[] = { -1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,14 };



	if (n > 14) {
		n = 0;
	}

	/* The below functions use the shifted registers to sum the incoming data and obtain the auto-correlated values*/
	int math_temp = C4_delay0[n] * data;
	C4_Delay0_Correlation = C4_Delay0_Correlation + math_temp;

	math_temp = C4_delay1[n] * data;
	C4_Delay1_Correlation = C4_Delay1_Correlation + math_temp;

	math_temp = C4_delay2[n] * data;
	C4_Delay2_Correlation = C4_Delay3_Correlation + math_temp;

	math_temp = C4_delay3[n] * data;
	C4_Delay3_Correlation = C4_Delay3_Correlation + math_temp;

	math_temp = C4_delay4[n] * data;
	C4_Delay4_Correlation = C4_Delay4_Correlation + math_temp;

	math_temp = C4_delay5[n] * data;
	C4_Delay5_Correlation = C4_Delay5_Correlation + math_temp;

	math_temp = C4_delay6[n] * data;
	C4_Delay6_Correlation = C4_Delay6_Correlation + math_temp;

	math_temp = C4_delay7[n] * data;
	C4_Delay7_Correlation = C4_Delay7_Correlation + math_temp;

	math_temp = C4_delay8[n] * data;
	C4_Delay8_Correlation = C4_Delay8_Correlation + math_temp;

	math_temp = C4_delay9[n] * data;
	C4_Delay9_Correlation = C4_Delay9_Correlation + math_temp;

	math_temp = C4_delay10[n] * data;
	C4_Delay10_Correlation = C4_Delay10_Correlation + math_temp;

	math_temp = C4_delay11[n] * data;
	C4_Delay11_Correlation = C4_Delay11_Correlation + math_temp;

	math_temp = C4_delay12[n] * data;
	C4_Delay12_Correlation = C4_Delay12_Correlation + math_temp;

	math_temp = C4_delay13[n] * data;
	C4_Delay13_Correlation = C4_Delay13_Correlation + math_temp;

	math_temp = C4_delay14[n] * data;
	C4_Delay14_Correlation = C4_Delay14_Correlation + math_temp;

	data_tracker = data_tracker + 1;



	if (data_tracker == 2310) {
		data_tracker = 0;
		float tracker_math = C4_Delay0_Correlation / 2310;

		if (tracker_math < 0) {
			return C4_delay0;
		}

		if ((C4_Delay1_Correlation / 2310) < 0) {
			return C4_delay1;
		}

		if ((C4_Delay2_Correlation / 2310) < 0) {
			return C4_delay2;
		}

		if ((C4_Delay3_Correlation / 2310) < 0) {
			return C4_delay3;
		}

		if ((C4_Delay4_Correlation / 2310) < 0) {
			return C4_delay4;
		}

		if ((C4_Delay5_Correlation / 2310) < 0) {
			return C4_delay5;
		}

		if ((C4_Delay6_Correlation / 2310) < 0) {
			return C4_delay6;
		}

		if ((C4_Delay7_Correlation / 2310) < 0) {
			return C4_delay7;
		}

		if ((C4_Delay8_Correlation / 2310) < 0) {
			return C4_delay8;
		}

		if ((C4_Delay9_Correlation / 2310) < 0) {
			return C4_delay9;
		}

		if ((C4_Delay10_Correlation / 2310) < 0) {
			return C4_delay10;

		}

		if ((C4_Delay11_Correlation / 2310) < 0) {
			return C4_delay11;
		}

		if ((C4_Delay12_Correlation / 2310) < 0) {
			return C4_delay12;
		}

		if ((C4_Delay13_Correlation / 2310) < 0) {
			return C4_delay13;
		}

		if ((C4_Delay14_Correlation / 2310) < 0) {
			return C4_delay14;
		}


	}
	n++;
	return C4_0;
}

