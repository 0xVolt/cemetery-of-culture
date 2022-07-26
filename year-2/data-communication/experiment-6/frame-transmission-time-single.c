// Code by Desh Iyer

// PROBLEM STATEMENT:
// Compute the total frame transmission times of 1 frame

// Include libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    printf("Code by Desh Iyer, SAP Id 500081889\n\n");

    // Initialize variables
    int transmissionTime = 1, propagationTime, R, flag;
    int k = 0, kmax = 15;
    double slotTime, backoffTime, totalTime;
    
    // Initialize propagation time
    propagationTime = 2 * transmissionTime;

    // Make slot time 1.5 micro seconds
    slotTime = 1.5 * pow(10, -6);

    // Taking the current time as the seed for random number generation
    srand(time(0));

    printf("Start of loop:\n");
    while (k <= kmax) {
        // Initialize flag to have either 0 or 1 value
        flag = rand() % 2;

        // Printing iteration details
        printf("Attempt (k): %d | flag: %d\n", k, flag);

        if (flag == 0) {
            // Increment count
            k++;

            // Calculate R
            R = pow(2, k) - 1;

            // Calculate backoff time
            int getRandomBetween = rand() % R;
            backoffTime = getRandomBetween * slotTime;

            // Calculate total time
            totalTime += backoffTime + propagationTime;
        } else {
            printf("\nFlag is 1. Exiting loop!\n");
            totalTime += propagationTime;
            break;
        }

        if (k == kmax + 1) {
            printf("\nKmax reached!\n");
        }
    }

    printf("\nThe total time taken for frame transmission is: %.2lf seconds", totalTime);
}