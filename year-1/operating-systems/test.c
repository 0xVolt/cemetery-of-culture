#include <stdio.h>

int main()
{
    int burst_time[100], p[100], wait_time[100], turnat[100], i, j, n, total = 0, position, temp;
    float avg_wait_time, avg_turnat;
    printf("\nEnter number of process:\n");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        scanf("%d", &burst_time[i]);
        p[i] = i + 1;
    }

    //Sorting the process with respect to burst time
    for (i = 0; i < n; i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[j] < burst_time[position])
                position = j;
        }

        temp = burst_time[i]; //array sorting
        burst_time[i] = burst_time[position];
        burst_time[position] = temp;

        temp = p[i]; //process sorting
        p[i] = p[position];
        p[position] = temp;
    }

    wait_time[0] = 0;

    for (i = 1; i < n; i++)
    {
        wait_time[i] = 0;
        for (j = 0; j < i; j++)
            wait_time[i] += burst_time[j];

        total += wait_time[i];
    }

    avg_wait_time = (float)total / n;
    total = 0;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        turnat[i] = burst_time[i] + wait_time[i];
        total += turnat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, burst_time[i], wait_time[i], turnat[i]);
    }

    avg_turnat = (float)total / n;
    printf("\nAverage Waiting Time=%f\n", avg_wait_time);
    printf("\nAverage Turnaround Time=%f\n", avg_turnat);
}