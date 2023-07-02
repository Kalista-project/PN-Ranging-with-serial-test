
#include "PNRanging_Functions.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>



int * correlator_task(data) {
	
	uint8_t convert_to_base10_raw = data; //takes incoming data into the function and converts to a base 10 format
	//printf("integer value: %d\n", convert_to_base10); // print each value in hexadecimal format
	
	int convert_to_base10 = (int)convert_to_base10_raw;
	char byte_data[] = "00000000";
	static int * composite_code_char[289];
	static int* code_returned[289] = {0};
	int k = 0;
	int C1_index = 0;/*These are used an index tools to cycle through the values of the correlator*/
	int C2_index = 0;
	int C3_index = 0;
	int C4_index = 0;
	int sign_holder = 0;
	int composite_code[2310] = { 0 };
	int n = 0;
	int s = 0;
	int binaryNum[8] = { 0 };
	static int* no_data[289] = {0};



	while (convert_to_base10 > 0) { // this is used to convert from base 10 to binary
		binaryNum[n] = convert_to_base10 % 2;
		convert_to_base10 = convert_to_base10 / 2;
		n++;
	}


	while (n <= 7) { //this fills the array with 0's if the converted value is not 8 bits long
		binaryNum[n] = 0;
		n++;
	}

	int length = sizeof(binaryNum) / sizeof(binaryNum[0]); //find the length of the array which is always 8, but the code

	for (int k = 0; k <= 7; k++) {
		if (binaryNum[k] == 0) {
			binaryNum[k] = -1;
		}


	}

	while (length >= 1) {
		length--;
		int *C1_array = C1(binaryNum[length]);

		int* C2_array = C2(binaryNum[length]);

		int* C3_array = C3(binaryNum[length]);

		int* C4_array = C4(binaryNum[length]);

		int bit_number = 1;

		if (C2_array[0] > -2) { /*The returned value of C2 is always less than -2 until the correlators find the delay position of the composite code.
		*Note* that this only occurs when 2310 bits are processed by the correlators*/

			while (bit_number < 2310) { /*Used for indexing the composite code sequence*/
				int summation = 2 * C1_array[C1_index] + C2_array[C2_index] - C3_array[C3_index] - C4_array[C4_index]; /*this is the calculation that is used to determine the
				composite code, minus the signum value*/

				if (summation > 0) { /*this is used to calculate the signum value since a function doesn't exist in C*/
					sign_holder = 1;
				}
				else
					sign_holder = -1;

				composite_code[bit_number] = sign_holder; /*generates the value that is stored into the composite code array*/
				C1_index++; /*these are part of the indexing of the component sequences used in the the composite code
				(i.e. C1, C2, C3, and C4) */
				C2_index++;
				C3_index++;
				C4_index++;

				if (C1_index == 2) { /*these functions are used to reset the indexing position of the component sequences.
				This is done because certain component sequences need to be repeated as part of the generation
				of the composite code */
					C1_index = 0;
				}

				if (C2_index == 7) {
					C2_index = 0;
				}

				if (C3_index == 11) {
					C3_index = 0;
				}

				if (C4_index == 15) {
					C4_index = 0;
				}

				bit_number++; /*increases the index used to index the composite code*/
			}

			// Code goes here .....
			size_t length_data = sizeof(composite_code) / sizeof(composite_code[0]);
			
			for (int i = 1; i < length_data + 1; i++) {
				if (composite_code[i] == 1) {
					byte_data[k] = '1';
					//printf("Data from Byte: %s", byte_data[k]);
					k++;
				}
				if (composite_code[i] == -1) {
					byte_data[k] = '0';
					//printf("Data from Byte: %s", byte_data[k]);
					k++;
				}
				if (k == 8) {
					//printf("Data from Composite Code Byte: %s\n", byte_data);
					// this needs to go somewhere, right now this variable is unused
					if (s == 0) {
						//printf("\n");
						//printf("Data from Composite Code Byte Variable:");
					}
					composite_code_char[s] = (int)strtol(byte_data, 0, 2);
					//printf("%d, ", composite_code_char[s]);
					k = 0;
					s++;
					if (s == 289) {
						s = 0;
					}
				}


			}

			static int test[289];

			printf("Results from correlator: \n");
			for (int k = 0; k < 288; k++) {
				printf("%d, ", composite_code_char[k]);
				test[k] = composite_code_char[k];
			}

			/*printf("\nResults from correlator: \n");
			for (int k = 0; k < 288; k++) {
				printf("%d, ", test[k]);
			}
			*/
			for (int n = 0; n < 288; n++) {
				
			}
		

			return  test;
			//for (int k = 0; k <= 2309; k++) {
			//	printf("%d", composite_code[k]);
			//}

		}
	}
	
	return;
	//==================================================
}




