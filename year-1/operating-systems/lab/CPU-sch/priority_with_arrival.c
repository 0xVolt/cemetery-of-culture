#include <stdio.h>
#include <conio.h>

void main() {
    int et[20], at[10], n, i, j, temp, p[10], st[10], ft[10], wt[10], ta[10];
    int totwt = 0, totta = 0;
    float awt, ata;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time & priority:\n");
        scanf("%d%d%d", &at[i], &et[i], &p[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i] < p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = et[i];
                et[i] = et[j];
                et[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            st[i] = at[i];
            wt[i] = st[i] - at[i];
            ft[i] = st[i] + et[i];
            ta[i] = ft[i] - at[i];
        } else {
            st[i] = ft[i - 1];
            wt[i] = st[i] - at[i];
            ft[i] = st[i] + et[i];
            ta[i] = ft[i] - at[i];
        }
        totwt += wt[i];
        totta += ta[i];
    }

    awt = (float)totwt / n;
    ata = (float)totta / n;

    printf("\nArrival Time\tBurst Time\tPriority\tWaiting Time\tTA Time");

    for (i = 0; i < n; i++)
        printf("\n%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d", at[i], et[i], p[i], wt[i], ta[i]);

    printf("\nAverage Waiting Time     : %.2f", awt);
    printf("\nAverage Turnaround Time  : %.2f", ata);
    getch();
}