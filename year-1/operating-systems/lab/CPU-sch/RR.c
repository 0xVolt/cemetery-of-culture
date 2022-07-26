/* Code by Desh Iyer 

Program to illustrate the working of Round Robin CPU Scheduling Algorithm using C */

#include <stdio.h>
#include <stdbool.h>  /* For 'bool' datatype */

#define N 20  /* Max number of processes is 20 */

void findAvgTime(int, int [], int [], int);
void getWaitingTime(int, int [], int [], int [], int);
void getTurnaroundTime(int, int [], int [], int [], int[]);

/* Start of main() function */
int main() {
    int n, pid[N], bt[N], tq;

    printf("Enter the number of processes (Max 20): ");
    scanf("%d", &n);

    printf("\nEnter the Process IDs and Burst Times for each of the processes:\n\n");
    for (int i = 0; i < n; i ++) {
        printf("Process #%d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &pid[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("\n");
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    findAvgTime(n, pid, bt, tq);

    return 0;
}   /* End of main() function */

void findAvgTime(int n, int pid[], int bt[], int tq) {
    int wt[n], tat[n], totalWT = 0, totalTAT = 0;

    /* First calculate Waiting Time */
    getWaitingTime(n, pid, bt, wt, tq);

    /* Since TAT = BT + WT */
    getTurnaroundTime(n, pid, bt, tat, wt);

    printf("Process No.\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");

    /* Displaying results and calculating Total WT and Total TAT */
    for (int i = 0; i < n; i ++) {
        totalWT += wt[i];
        totalTAT += tat[i];

        /* Displaying Table */
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float) totalWT / (float) n);
    printf("\nAverage Turnaround Time = %.2f", (float) totalTAT / (float) n);
}

/* Function to calculate the Waiting Time for each process */
void getWaitingTime(int n, int pid[], int bt[], int wt[], int tq) {
    /* Make a copy of the burst times */
    int rem_bt[n];
    for (int i = 0; i < n; i ++) {
        rem_bt[i] = bt[i];
    }

    int t = 0;  /* Current time */

    /* Keep traversing all the processes in Round Robin manner using infinite while loop till all are done */
    while (true) {
        bool done = true;   /* Flag variable that updates to true after every iteration to check whether ALL processes are done */

        for (int i = 0; i < n; i ++) {
            if (rem_bt[i] > 0) {
                done = false;   /* Process pending */

                if (rem_bt[i] > tq) {
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    /* Code executes if rem_bt[i] <= tq, i.e. last iteration for that process */
                    t += rem_bt[i]; /* Total time taken for process execution */

                    wt[i] = t - bt[i];  /* waiting time = total time taken - origianl burst time */
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == true) {
            break;
        }
    }
}   /* End of getWaitingTime() */

/* Function to calculate Turnaround Times for each process */
void getTurnaroundTime(int n, int pid[], int bt[], int tat[], int wt[]) {
    for (int i = 0; i < n; i ++) {
        tat[i] = wt[i] + bt[i]; /* Turnaround time = burst time + waiting time */
    }
}   /* End of getTurnaroundTime() */