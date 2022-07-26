#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
    int waitTime;
    int turnTime;
};

void calcWaitTime(struct Process [], int);
void calcTurnTime(struct Process [], int);

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
    printf("\nSorting processes by burst time:\n");
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

    calcWaitTime(p, n);
    calcTurnTime(p, n);

    int totalWT = 0;
    int totalTT = 0;

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

    printf("\n\nThe Average Waiting time is = %.2f", (float)totalWT / (float)n);
    printf("\nThe Average Turnaround time is = %.2f", (float)totalTT / (float)n);

    printf("\n\n");

    return 0;
}

void calcWaitTime(struct Process p[], int n) {
    p[0].waitTime = 0;

    for (int i = 1; i < n; i++) {
        p[i].waitTime = p[i - 1].waitTime + p[i - 1].burstTime;
    }
}

void calcTurnTime(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnTime = p[i].waitTime + p[i].burstTime;
    }
}