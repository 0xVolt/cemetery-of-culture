/*
We input number of processes, process id's and their burst times
Get process id and and burst time from user 

In which order the processes come in, we take it as it is

For First Come First Serve:
    We need to calculate average waiting time for each process
        Waiting time for first process is 0
        To calc for other processes
    Calculate the turnaround time
*/

#include <stdio.h>

void calcWaitingTime(int pids[], int n, int burstTimes[], int waitingTimes[]);
void calcTurnTime(int pids[], int n, int burstTimes[], int waitingTimes[], int turnaroundTimes[]);

int main() {
    int n, i, pids[25], burstTimes[25], waitingTimes[25], turnaroundTimes[25];
    int totalWT, totalTT;
    totalTT = totalWT = 0;

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

    calcWaitingTime(pids, n, burstTimes, waitingTimes);
    calcTurnTime(pids, n, burstTimes, waitingTimes, turnaroundTimes);

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

    printf("\n\nAverage turnaround time = %.3f", (float)totalTT / (float)n);
    printf("\nAverage waiting time = %.3f", (float)totalWT / (float)n);

    printf("\n\n");
}

void calcWaitingTime(int pids[], int n, int burstTimes[], int waitingTimes[]) {
    waitingTimes[0] = 0;

    for (int i = 1; i < n; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
    }
}

void calcTurnTime(int pids[], int n, int burstTimes[], int waitingTimes[], int turnaroundTimes[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }
}