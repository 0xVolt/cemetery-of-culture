// Code by Desh Iyer

// Include libraries
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define KMAX 15
using namespace std;

// Function prototype(s)
void calculateTotalTime(int, double *, double *, double *);

// Start of main()
int main() {
    int numberFrames;

    // Input number of frames to calculate for
    cout << "Enter the number of frames: ";
    cin >> numberFrames;

    // To write the output from the stdout stream to a file
    freopen("out.csv", "w", stdout);

    // Create 3 arrays by dynamic memory allocation
    double *totalTimeForNFrames = (double *) malloc(numberFrames * sizeof(double));
    double *totalAttemptsForNFrames = (double *) malloc(numberFrames * sizeof(double));
    double *backoffTimeForNFrames = (double *) malloc(numberFrames * sizeof(double));

    // Function call
    calculateTotalTime(numberFrames, totalTimeForNFrames, totalAttemptsForNFrames, backoffTimeForNFrames);

    // Printing results in a comma separated fashion to export stdout to a csv file
    cout << "Frame (#),Attempts (k),Total Time Taken (seconds),Backoff Time (seconds),\n";
    for (int i = 0; i < numberFrames; i++) {
        printf("%d,%.2lf,%.2f,%lf,\n", (i + 1), totalAttemptsForNFrames[i], totalTimeForNFrames[i], backoffTimeForNFrames[i]);
    }

    return 0;
} // End of main()

// Function to calculate the total frame transmission time for n frames and populate arrays with values
void calculateTotalTime(int n, double *totalTimeArr, double *totalAttemptsArr, double *backoffTimeArr) {
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

        // Populate arrays
        totalTimeArr[i] = totalTime;
        totalAttemptsArr[i] = sumAttempts;
        backoffTimeArr[i] = backoffTime;
    }
}