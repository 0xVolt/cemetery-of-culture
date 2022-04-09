// Code by Desh Iyer

// DOES NOT WORK.

// PROBLEM STATEMENT:
// Compute the total frame transmission times of N frames

// Include libraries
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define KMAX 15
using namespace std;

fstream file;

void menu();
void calculateTotalFrameTransmissionTime(int);
void populateArrays(int, double *, double *, double *);

// Start of main()
int main() {
    cout << "Code by Desh Iyer, SAP Id 500081889\n\n";

    // Call the menu function
    menu();

    return 0;
} // End of main()


void menu() {
    // FILE *fp;
    char ans;
    int option;

    // Start exit-controlled loop
    do {
        cout << "Menu\n\n";
        cout << "1. Write a new output file\n";
        cout << "2. Append output to existing file\n";
        cout << "3. Exit\n\n";
        cout << "Select an option (1, 2, 3): ";
        
        cin >> option;
    
        int numberFrames;

        // Input number of frames to calculate for
        cout << "Enter the number of frames: ";
        cin >> numberFrames;

        switch (option) {
            // Create a new file and write to it
            case 1:
                // To write the output from the stdout stream to a file
                // fp = freopen("output.csv", "w", stdout);
                file.open("output.csv", ios :: out);
                calculateTotalFrameTransmissionTime(numberFrames);
                break;

            // Append to the existing file
            case 2:
                // fp = freopen("output.csv", "a", stdout);
                file.open("output.csv", ios :: app);
                calculateTotalFrameTransmissionTime(numberFrames);
                break;

            // Exit
            case 3:
                exit(0);
        }

        // fclose(fp);

        // Input choice to continue the menu
        cout << "\n\nContinue? (Y/N): ";
        cin >> ans;
        // Continue the menu as long as the answer is YES
    } while (ans == 'y' || ans == 'Y');
}


void calculateTotalFrameTransmissionTime(int numberFrames) {
    // Declare arrays dynamically
    double *totalTimeForNFrames = (double *) malloc(numberFrames * sizeof(double));
    double *totalAttemptsForNFrames = (double *) malloc(numberFrames * sizeof(double));
    double *backoffTimeForNFrames = (double *) malloc(numberFrames * sizeof(double));

    populateArrays(numberFrames, totalTimeForNFrames, totalAttemptsForNFrames, backoffTimeForNFrames);

    file << "Frame (#),Attempts (k),Total Time Taken (seconds),Backoff Time (seconds),\n";
    for (int i = 0; i < numberFrames; i++) {
        file << (i + 1) << "," << totalAttemptsForNFrames[i] << "," << totalTimeForNFrames << "," << backoffTimeForNFrames[i] << ",\n";
        
        // printf("%d,%.2lf,%.2f,%lf,\n", (i + 1), totalAttemptsForNFrames[i], totalTimeForNFrames[i], backoffTimeForNFrames[i]);
    }
}


void populateArrays(int n, double *totalTimeArr, double *totalAttemptsArr, double *backoffTimeArr) {
    // Taking the current time as the seed for random number generation
    srand(time(0));

    // Calculate relevant details for each frame and append to the result arrays
    for (int i = 0; i < n; i++) {
        // Initialize variables
        int transmissionTime = 1, propagationTime = 0, R, flag, k = 0;
        double slotTime, backoffTime, totalTime = 0, sumAttempts = 1;
        
        // Initialize propagation time
        propagationTime = 2 * transmissionTime;

        // Make slot time 1.5 micro seconds
        slotTime = 1.5 * pow(10, -6);

        // printf("\nStart of loop:\n");
        while (k <= KMAX) {
            // Initialize flag to have either 0 or 1 value
            flag = rand() % 2;

            // Check condition
            if (flag == 0) {
                // Do this if flag == 0
                // Increment count
                k++;
                sumAttempts++;

                // Calculate R
                R = pow(2, k) - 1;

                // Calculate backoff time
                int getRandomBetween = rand() % R;
                backoffTime = getRandomBetween * slotTime;

                // Calculate total time
                totalTime += backoffTime + propagationTime;
            } else {
                // Do this if the flag == 1
                totalTime += propagationTime;
                break;
            }
        }

        totalTimeArr[i] = totalTime;
        totalAttemptsArr[i] = sumAttempts;
        backoffTimeArr[i] = backoffTime;
    }
}