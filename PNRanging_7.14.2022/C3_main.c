#include <stdio.h>
#include "PNRanging_Functions.h"


static int C3_0[] = { -5 };


int* C3(data) {

    /* Initalizing correlators arrays. These will hold the corresponding component sequences for the delay.
    They are allocated for a component sequences corresponding to a Tausworth length 4 code. */
    static int n = 0;
    static float C3_Delay0_Correlation = 0;
    static float C3_Delay1_Correlation = 0;
    static float C3_Delay2_Correlation = 0;
    static float C3_Delay3_Correlation = 0;
    static float C3_Delay4_Correlation = 0;
    static float C3_Delay5_Correlation = 0;
    static float C3_Delay6_Correlation = 0;
    static float C3_Delay7_Correlation = 0;
    static float C3_Delay8_Correlation = 0;
    static float C3_Delay9_Correlation = 0;
    static float C3_Delay10_Correlation = 0;

    static int data_tracker = 0;

    static int C3_delay0[] = { 1,1,1,-1,-1,-1,1,-1,1,1,-1,0 };
    static int C3_delay1[] = { 1,1,-1,-1,-1,1,-1,1,1,-1,1,1 };
    static int C3_delay2[] = { 1,-1,-1,-1,1,-1,1,1,-1,1,1,2 };
    static int C3_delay3[] = { -1,-1,-1,1,-1,1,1,-1,1,1,1,3 };
    static int C3_delay4[] = { -1,-1,1,-1,1,1,-1,1,1,1,-1,4 };
    static int C3_delay5[] = { -1,1,-1,1,1,-1,1,1,1,-1,-1,5 };
    static int C3_delay6[] = { 1,-1,1,1,-1,1,1,1,-1,-1,-1,6 };
    static int C3_delay7[] = { -1,1,1,-1,1,1,1,-1,-1,-1,1,7 };
    static int C3_delay8[] = { 1,1,-1,1,1,1,-1,-1,-1,1,-1,8 };
    static int C3_delay9[] = { 1,-1,1,1,1,-1,-1,-1,1,-1,1,9 };
    static int C3_delay10[] = { -1,1,1,1,-1,-1,-1,1,-1,1,1,10 };

    if (n > 10) {
        n = 0;
    }

    /* The below functions use the shifted registers to sum the incoming data and obtain the auto-correlated values*/
    int math_temp = C3_delay0[n] * data;
    C3_Delay0_Correlation = C3_Delay0_Correlation + math_temp;

    math_temp = C3_delay1[n] * data;
    C3_Delay1_Correlation = C3_Delay1_Correlation + math_temp;

    math_temp = C3_delay2[n] * data;
    C3_Delay2_Correlation = C3_Delay3_Correlation + math_temp;

    math_temp = C3_delay3[n] * data;
    C3_Delay3_Correlation = C3_Delay3_Correlation + math_temp;

    math_temp = C3_delay4[n] * data;
    C3_Delay4_Correlation = C3_Delay4_Correlation + math_temp;

    math_temp = C3_delay5[n] * data;
    C3_Delay5_Correlation = C3_Delay5_Correlation + math_temp;

    math_temp = C3_delay6[n] * data;
    C3_Delay6_Correlation = C3_Delay6_Correlation + math_temp;

    math_temp = C3_delay7[n] * data;
    C3_Delay7_Correlation = C3_Delay7_Correlation + math_temp;

    math_temp = C3_delay8[n] * data;
    C3_Delay8_Correlation = C3_Delay8_Correlation + math_temp;

    math_temp = C3_delay9[n] * data;
    C3_Delay9_Correlation = C3_Delay9_Correlation + math_temp;

    math_temp = C3_delay10[n] * data;
    C3_Delay10_Correlation = C3_Delay10_Correlation + math_temp;

    data_tracker = data_tracker + 1;



    if (data_tracker == 2310) {
        data_tracker = 0;
        float tracker_math = C3_Delay0_Correlation / 2310;

        if (tracker_math < 0) {
            return C3_delay0;
        }

        if ((C3_Delay1_Correlation / 2310) < 0) {
            return C3_delay1;
        }

        if ((C3_Delay2_Correlation / 2310) < 0) {
            return C3_delay2;
        }

        if ((C3_Delay3_Correlation / 2310) < 0) {
            return C3_delay3;
        }

        if ((C3_Delay4_Correlation / 2310) < 0) {
            return C3_delay4;
        }

        if ((C3_Delay5_Correlation / 2310) < 0) {
            return C3_delay5;
        }

        if ((C3_Delay6_Correlation / 2310) < 0) {
            return C3_delay6;
        }

        if ((C3_Delay7_Correlation / 2310) < 0) {
            return C3_delay7;
        }

        if ((C3_Delay8_Correlation / 2310) < 0) {
            return C3_delay8;
        }

        if ((C3_Delay9_Correlation / 2310) < 0) {
            return C3_delay9;
        }

        if ((C3_Delay10_Correlation / 2310) < 0) {
            return C3_delay10;
        }
    }

    n++;
    return C3_0;
}