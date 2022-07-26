/* Code by Desh Iyer 

Program to illustrate the working of Priority CPU Scheduling Algorithm without Arrival Time using C */

#include <stdio.h>

/* Structure definition */
struct Process {
    int id;        /* Process ID */
    int bt;        /* Burst Time */
    int wt;        /* Waiting Time */
    int tat;       /* Turnaround Time */
    int priority;  /* Process Priority */
}; 

/* Function declarations */
void getAvgTime(struct Process [], int);
void sortPriority(struct Process [], int);
void getWaitingTime(struct Process [], int);
void getTurnaroundTime(struct Process [], int);

/* Start of main() function */
int main() {
    int n;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);  

    struct Process p[n];

    printf("Enter the following details:\n");
    for (int i = 0; i < n; i ++) {
        p[i].id = i + 1;

        printf("Process #%d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    sortPriority(p, n);
    printf("\nOrder of execution of processes:\n");
    for (int i = 0; i < n; i ++) {
        printf("%d ", p[i].id);
    }
    printf("\n\n");

    getWaitingTime(p, n);
    getTurnaroundTime(p, n);

    getAvgTime(p, n);

    return 0;
}   /* End of main() function */

/* Function to sort the processes by decreasing priority, i.e. increasing priority number */
void sortPriority(struct Process p[], int n) {
    int i, j;
    struct Process temp;    /* temporary structure variable */

    /* Bubble Sort algorithm */
    for (i = 0; i < n - 1; i ++) {
        for (j = 0; j < n - i - 1; j ++) {
            if (p[j].priority > p[j + 1].priority) {
                temp.priority = p[j].priority;
                temp.id = p[j].id;
                temp.bt = p[j].bt;
                temp.wt = p[j].wt;
                temp.tat = p[j].tat;
                
                p[j].priority = p[j + 1].priority;
                p[j].id = p[j + 1].id;
                p[j].bt = p[j + 1].bt;
                p[j].wt = p[j + 1].wt;
                p[j].tat = p[j + 1].tat;

                p[j + 1].priority = temp.priority;
                p[j + 1].id = temp.id;
                p[j + 1].bt = temp.bt;
                p[j + 1].wt = temp.wt;
                p[j + 1].tat = temp.tat;
            }
        }
    }
}

/* Function to calculate the waiting time of each process */
void getWaitingTime(struct Process p[], int n) {
    p[0].wt = 0;

    for (int i = 1; i < n; i ++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
}

/* Function to calculate the turnaround time of each process */
void getTurnaroundTime(struct Process p[], int n) {
    for (int i = 0; i < n; i ++) {
        p[i].tat = p[i].bt + p[i].wt;
    }
}

/* Function to calculate average waiting and turnaround times and display all data in the form of a table  */
void getAvgTime(struct Process p[], int n) {
    int totalWT = 0, totalTAT = 0;
    
    printf("Priority\tProcess No.\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");

    for (int i = 0; i < n; i ++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;

        /* Displaying Table */
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].priority, p[i].id, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", (float) totalWT / (float) n);
    printf("\nAverage Turnaround Time = %.2f", (float) totalTAT / (float) n);
}