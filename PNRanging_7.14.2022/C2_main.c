#include <stdio.h>
#include "PNRanging_Functions.h"


static int  C2_0[] = { -5 };


int* C2(data) {

    /* Initalizing correlators arrays. These will hold the corresponding component sequences for the delay.
    They are allocated for a component sequences corresponding to a Tausworth length 4 code. */
    static int C2_delay0[] = { 1,1,1,-1,-1,1,-1,0 };
    static int C2_delay1[] = { 1,1,-1,-1,1,-1,1,1 };
    static int C2_delay2[] = { 1,-1,-1,1,-1,1,1,2 };
    static int C2_delay3[] = { -1,-1,1,-1,1,1,1,3 };
    static int C2_delay4[] = { -1,1,-1,1,1,1,-1,4 };
    static int C2_delay5[] = { 1,-1,1,1,1,-1,-1,5 };
    static int C2_delay6[] = { -1,1,1,1,-1,-1,1,6 };

    static int data_tracker = 0;

    static float C2_Delay0_Correlation = 0;
    static float C2_Delay1_Correlation = 0;
    static float C2_Delay2_Correlation = 0;
    static float C2_Delay3_Correlation = 0;
    static float C2_Delay4_Correlation = 0;
    static float C2_Delay5_Correlation = 0;
    static float C2_Delay6_Correlation = 0;

    static int n = 0;

    if (n == 7) {
        n = 0;
    }


    /* The below functions use the shifted registers to sum the incoming data and obtain the auto-correlated values*/
    int math_temp = C2_delay0[n] * data;
    C2_Delay0_Correlation = C2_Delay0_Correlation + math_temp;

    math_temp = C2_delay1[n] * data;
    C2_Delay1_Correlation = C2_Delay1_Correlation + math_temp;

    math_temp = C2_delay2[n] * data;
    C2_Delay2_Correlation = C2_Delay2_Correlation + math_temp;

    math_temp = C2_delay3[n] * data;
    C2_Delay3_Correlation = C2_Delay3_Correlation + math_temp;

    math_temp = C2_delay4[n] * data;
    C2_Delay4_Correlation = C2_Delay4_Correlation + math_temp;

    math_temp = C2_delay5[n] * data;
    C2_Delay5_Correlation = C2_Delay5_Correlation + math_temp;

    math_temp = C2_delay6[n] * data;
    C2_Delay6_Correlation = C2_Delay6_Correlation + math_temp;

    data_tracker = data_tracker + 1;


    if (data_tracker == 2310) {
        data_tracker = 0;
        float tracker_math = C2_Delay0_Correlation / 2310;
        if (tracker_math > 0) {
            return C2_delay0;

        }
        if ((C2_Delay1_Correlation / 2310) > 0) {
            return C2_delay1;
        }

        if ((C2_Delay2_Correlation / 2310) > 0) {
            return C2_delay2;
        }

        if ((C2_Delay3_Correlation / 2310) > 0) {
            return C2_delay3;
        }

        if ((C2_Delay4_Correlation / 2310) > 0) {
            return C2_delay4;
        }
        if ((C2_Delay5_Correlation / 2310) > 0) {
            return C2_delay5;
        }

        if ((C2_Delay6_Correlation / 2310) > 0) {
            return C2_delay6;
        }
    }

    n++;


    return C2_0;
}