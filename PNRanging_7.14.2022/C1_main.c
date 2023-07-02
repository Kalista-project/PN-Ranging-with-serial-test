#include <stdio.h>
#include "PNRanging_Functions.h"



static int n = 0;
static float C1_Delay0_Correlation = 0;
static float C1_Delay1_Correlation = 0;
static int C1_0[] = { -6,-5 };

int * C1(data) {

    /* Initalizing correlators arrays. These will hold the corresponding component sequences for the delay.
    They are allocated for a component sequences corresponding to a Tausworth length 4 code. */

    static int C1_delay0[] = { 1,-1, 0 };
    static int C1_delay1[] = { -1, 1, 1 };
    static int data_tracker = 0;


    if (n >= 2) {
        n = 0;
    }

    /* The below functions use the shifted registers to sum the incoming data and obtain the auto-correlated values*/

    int math_temp = C1_delay0[n] * data;


    C1_Delay0_Correlation = C1_Delay0_Correlation + math_temp;

    math_temp = C1_delay1[n] * data;
    C1_Delay1_Correlation = C1_Delay1_Correlation + math_temp;

    data_tracker = data_tracker + 1;

    if (data_tracker == 2310) {
        data_tracker = 0;
        float tracker_math = C1_Delay0_Correlation / 2310;

        if (tracker_math > 0) {
            return C1_delay0;

        }
        else if ((C1_Delay1_Correlation / 2310) > 0) {
            return C1_delay1;
        }
    }
    n++;
    return C1_0;
}

