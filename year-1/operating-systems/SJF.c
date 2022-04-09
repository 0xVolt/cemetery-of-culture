/* Code by Desh Iyer */
/* Program to demonstrate Shortest Job First CPU Scheduling Algorithm */

#include <stdio.h>

/* To try a different method to FCFS CPU Scheduling, taking array of structure variables
enabled me to sort two arrays at once and store the results of wait time and turnaround time in the same array
of structure variables */
struct Process {
    int pid;
    int burstTime;
    int waitTime;
    int turnTime;
};

/* Function declarations */
void calcWaitTime(struct Process [], int);
void calcTurnTime(struct Process [], int);

/* Start of main function */
int main() {
    struct Process p[25], temp;
    int i, j, n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter details:\n\n");
    for (i = 0; i < n; i++) {
        printf("Enter process id #%d: ", (i + 1));
        scanf("%d", &p[i].pid);
        printf("Enter the burst time of process #%d: ", (i + 1));
        scanf("%d", &p[i].burstTime);
        printf("\n");
    }

    /* Sorting the array 'p' by burst time using bubble sort alg */
    printf("\nSorting processes by increasing order of burst time:\n");
    /* Generic bubble sort algorithm */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].burstTime > p[j + 1].burstTime) {
                temp.burstTime = p[j].burstTime;
                temp.pid = p[j].pid;

                p[j].burstTime = p[j + 1].burstTime;
                p[j].pid = p[j + 1].pid;

                p[j + 1].burstTime = temp.burstTime;
                p[j + 1].pid = temp.pid;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", p[i].burstTime);
    }

    /* The advantage of using structures is highlighted by the fact that multiple arrays need not be created
    to store waiting time, burst time, etc. */
    calcWaitTime(p, n);
    calcTurnTime(p, n);

    int totalWT = 0;
    int totalTT = 0;

    /* Printing results */
    printf("\n\nThe Waiting times for the processes are:\n\n");
    for (i = 0; i < n; i++) {
        totalWT += p[i].waitTime;
        printf("%d ", p[i].waitTime);
    }

    printf("\n\nThe Turnaround times for the processes are:\n\n");
    for (i = 0; i < n; i++) {
        totalTT += p[i].turnTime;
        printf("%d ", p[i].turnTime);
    }

    /* Display avg waitting and turnaround times */
    printf("\nThe Average Waiting time is = %.2f", (float)totalWT / (float)n);
    printf("\nThe Average Turnaround time is = %.2f", (float)totalTT / (float)n);

    printf("\n\n");

    return 0;
}/* End of main function */

/* Function to calculate the waiting time for each process. The function takes an array of structure variables
and the number of processes as arguments */
void calcWaitTime(struct Process p[], int n) {
    /* The waiting time for the first process is always 0 since it is first to be executed */
    p[0].waitTime = 0;

    for (int i = 1; i < n; i++) {
        p[i].waitTime = p[i - 1].waitTime + p[i - 1].burstTime;
    }
}

/* Function to calculate the turnaround time. This function also takes an array of structure variables
and the number of processes as arguments */
void calcTurnTime(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnTime = p[i].waitTime + p[i].burstTime;
    }
}