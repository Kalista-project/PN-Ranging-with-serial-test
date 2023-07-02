#include "PNRanging_Functions.h"
#include <stdio.h>
#include <stdint.h>
#include <tchar.h>
#include <stdlib.h>
#include <Windows.h>




void main() {

	//======================================================
    // This section is used for testing and troubleshooting
    // 
    // This uses Windows 32 API to establish a serial
    // connection that can be used to test to see if the 
    // program is returning data properly
    //======================================================


    
    HANDLE hSerial;
    DCB dcbSerialParams = { 0 };
    COMMTIMEOUTS timeouts = { 0 };
    DWORD bytesRead, bytesWritten;
    char readBuffer[300];
    char writeBuffer[300] = " ";
    uint8_t data_to_send[289];

    // Open the serial port
    hSerial = CreateFile(L"COM2", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error opening serial port\n");
        return 1;
    }

    // Set serial port parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error getting serial port state\n");
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600;  // Set the baud rate
    dcbSerialParams.ByteSize = 8;         // Set the data size
    dcbSerialParams.Parity = NOPARITY;    // Set parity to none
    dcbSerialParams.StopBits = ONESTOPBIT;// Set stop bits to 1
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error setting serial port state\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Set timeouts
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        fprintf(stderr, "Error setting serial port timeouts\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Write data to the serial port
    if (!WriteFile(hSerial, writeBuffer, sizeof(writeBuffer), &bytesWritten, NULL)) {
        fprintf(stderr, "Error writing to serial port\n");
        CloseHandle(hSerial);
        return 1;
    }
    //printf("Bytes written: %lu\n", bytesWritten);

    // Read data from the serial port
    if (!ReadFile(hSerial, readBuffer, sizeof(readBuffer), &bytesRead, NULL)) {
        fprintf(stderr, "Error reading from serial port\n");
        CloseHandle(hSerial);
        return 1;
    }

	//=========================
    //The programs
    //========================

    for (;;) {
        char readBuffer[300] = "";
        if (!ReadFile(hSerial, readBuffer, sizeof(readBuffer), &bytesRead, NULL)) {
            fprintf(stderr, "Error reading from serial port\n");
            CloseHandle(hSerial);
            return 1;
        }
        size_t length_data = sizeof(readBuffer) / sizeof(readBuffer[0]);
        
        for (int i = 0; i < length_data; i++) { 
            uint8_t test =  readBuffer[i]; // moves the data from the buffer to a variable to check for 
            if (test != 0) {
                int * composite_code = correlator_task(readBuffer[i]);
                char code_out[290] = { ""};
                if (composite_code != 0) {
                    //printf("\n Main File Numbers: \n");
                    
                    for (int n = 0; n < 290; n++) {
                        
                        code_out[n] = (uint8_t)composite_code[n];
            
                    }

                    printf("\n Results from Buffer: \n");
                    printf("%s", readBuffer);

                    printf("\n Results from main program: \n");
                    printf("%s", code_out);
                }



            }
            
        }
     


        //correlator_task(readBuffer);
        

        /*static int* data_tracker = 0;
        char data = '0';
        char byte_data[] = "00000000";
        int k = 0;
        int composite_length = 288;
        for (int i = 1; i < length_data + 1; i++) {
            if (readBuffer[i] == 1) {
                byte_data[k] = '1';
                //printf("Data from Byte: %s", byte_data[k]);
                k++;
            }
            if (readBuffer[i] == -1) {
                byte_data[k] = '0';
                //printf("Data from Byte: %s", byte_data[k]);2);
                int* composite_code = correlator_task(data);
                k++;
            }
            if (k == 8) {
                data = strtol(byte_data, 0, 
                if (composite_code[0] >= 0)
                    for (int n = 0; n < composite_length; n++) {
                        printf("%d \n ", composite_code[n]);
                    }
                k = 0;
            }
        
        }
        */
    }
    return 0;
}

		
 