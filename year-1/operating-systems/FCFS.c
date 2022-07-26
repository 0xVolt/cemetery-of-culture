/* Code by Desh Iyer */
/* The following program illustrates First Come First Server CPU Scheduling algorithm */

/* Program outline:
We input number of processes, process id's and their burst times
Get process id and and burst time from user 

In which order the processes come in, we take it as it is

For First Come First Serve:
    We need to calculate average waiting time for each process
        Waiting time for first process is 0
        To calc for other processes
    Calculate the turnaround time */

#include <stdio.h>

/* Function declarations */
void calcWaitingTime(int pids[], int n, int burstTimes[], int waitingTimes[]);
void calcTurnTime(int pids[], int n, int burstTimes[], int waitingTimes[], int turnaroundTimes[]);

/* Start of main function */
int main() {
    /* Make separate arrays to store burst times, waiting times and turnaround times */
    int n, i, pids[25], burstTimes[25], waitingTimes[25], turnaroundTimes[25];
    int totalWT, totalTT;
    totalTT = totalWT = 0;

    /* Enter number of processes */
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process ids:\n\n");
    for (i = 0; i < n; i++) {
        printf("Enter process #%d: ", (i + 1));
        scanf("%d", &pids[i]);
    }

    printf("\nEnter burst times:\n\n");
    for (i = 0; i < n; i++) {
        printf("Enter burst time #%d: ", (i + 1));
        scanf("%d", &burstTimes[i]);
    }

    /* Function calls */
    calcWaitingTime(pids, n, burstTimes, waitingTimes);
    calcTurnTime(pids, n, burstTimes, waitingTimes, turnaroundTimes);

    /* Printing results */
    printf("\n\nWaiting times are:\n");
    for (i = 0; i < n; i++) {
        totalWT += waitingTimes[i];
        printf("%d ", waitingTimes[i]);
    }

    printf("\n\nTurnaround times are:\n");
    for (i = 0; i < n; i++) {
        totalTT += turnaroundTimes[i];
        printf("%d ", turnaroundTimes[i]);
    }

    /* Display avg waitting and turnaround times */
    printf("\n\nAverage turnaround time = %.3f", (float)totalTT / (float)n);
    printf("\nAverage waiting time = %.3f", (float)totalWT / (float)n);

    printf("\n\n");
}/* End of main function */

/* Function to calculate waiting time of each process. This function takes array of processes, number of processes, 
array of burst times and array of waiting times as arguments */
void calcWaitingTime(int pids[], int n, int burstTimes[], int waitingTimes[]) {
    /* The waiting time for the first process is always 0 since it is first to be executed */
    waitingTimes[0] = 0;

    for (int i = 1; i < n; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
    }
}

/* Function to calculate turnaround time of each process. This function also takes array of processes, 
number of processes, array of burst times and array of waiting times as arguments */
void calcTurnTime(int pids[], int n, int burstTimes[], int waitingTimes[], int turnaroundTimes[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }
}