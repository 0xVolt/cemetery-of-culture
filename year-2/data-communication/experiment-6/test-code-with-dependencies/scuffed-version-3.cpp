// Code by Desh Iyer

// -------------CAUTION---------------
// I WROTE THIS CODE LIKE HOW RIOT MAKES THEIR GAMES
// COMPLETELY BROKEN AND WITHOUT A CARE
// ty

// PROBLEM STATEMENT:
// Compute the total frame transmission times of N frames

// What graphs?
// [ ] - Frames v. Total Time
// [ ] - Backoff Time v. Frequency

// Include libraries
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <time.h>
#include <math.h>

// Include pbPlots libraries included locally
#include "pbPlots.hpp"
#include "supportLib.hpp"
#define KMAX 15
#define W 600
#define H 400
using namespace std;

void calculateTotalTime(int, vector<double>, vector<double>, vector<double>);

// Start of main()
int main() {
    cout << "Code by Desh Iyer, SAP Id 500081889\n\n";

    int numberFrames;

    // Input number of frames to calculate for
    cout << "Enter the number of frames: ";
    cin >> numberFrames;

    // To write the output from the stdout stream to a file
    freopen("output.csv", "w", stdout);

    vector<double> totalTimeForNFrames, totalAttemptsForNFrames, backoffTimeForNFrames;

    calculateTotalTime(numberFrames, totalTimeForNFrames, totalAttemptsForNFrames, backoffTimeForNFrames);

    // cout << "\n\nPrinting the resultant array of transmission times:\n";
    cout << "Frame (#),Attempts (k),Total Time Taken (seconds),Backoff Time (seconds),\n";
    for (int i = 0; i < numberFrames; i++) {
        printf("%d,%.2lf,%.2f,%lf,\n", (i + 1), totalAttemptsForNFrames[i], totalTimeForNFrames[i], backoffTimeForNFrames[i]);
    }

    // Do pbPlots stuff
    StringReference *errorMessage = new StringReference();

    // Create a RGBA Bitmap Image pointer
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference(); 

    bool success = DrawScatterPlot(imageReference, 600, 400, &totalTimeForNFrames, &totalAttemptsForNFrames, errorMessage);

    if(success) {
        vector<double> *pngdata = ConvertToPNG(imageReference->image);
        WriteToFile(pngdata, "example1.png");
        DeleteImage(imageReference->image);
	} else{
	    cerr << "Error: ";
        for(wchar_t c : *errorMessage->string){
            wcerr << c;
        }
        cerr << endl;
	}

	return success ? 0 : 1;
} // End of main()

void calculateTotalTime(int n, vector<double> totalTimeArr, vector<double> totalAttemptsArr, vector<double> backoffTimeArr) {
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