// Code by Desh Iyer
// Problem Statement 2

// Include libraries
#include <stdio.h>
#include <stdlib.h>

// Function prototype
float baudRateEstimate(float, float, int);

// Start of main()
int main() {
    // Declare variables
    int N;
    float c, r;

    // File pointers for reading and writing to file
    FILE *fin, *fout;

    // Open file data.txt in read mode
    fin = fopen("C:\\Users\\deshi\\Code\\cemetery-of-culture\\year-2\\data-communication\\experiment-2\\ps2\\data.txt", "r");
    
    // Open file data.txt in append mode - since we want to write to the same file
    fout = fopen
    ("C:\\Users\\deshi\\Code\\cemetery-of-culture\\year-2\\data-communication\\experiment-2\\ps2\\output.txt", "w");

    // Loop through the file using fin
    while (!feof(fin)) {
        for (int i = 0; i < 10; i++) {
            // Read the file and store the values in variables
            fscanf(fin, "%d %f %f", &N, &c, &r);

            // Calculate S and print details
            float S = baudRateEstimate(c, r, N);
            printf("Baud Rate calculated #%d: %.2f baud(s)\n", i + 1, S);

            // Write result to the same file using fout
            fprintf(fout, "%d: %.2f baud(s)\n", i + 1, S);
        }
    }

    // Confirmation message
    printf("\nDetails successfully written to the file\n\n");

    // Deallocate file pointers
    fclose(fin);
    fclose(fout);
    return 0;
} // End of main()

// Function definition
float baudRateEstimate(float c, float r, int N) {
    float S = c * N * (1 / r);
    return S;
}