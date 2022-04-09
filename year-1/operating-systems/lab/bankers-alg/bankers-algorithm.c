/* Code by Desh Iyer
* Program to implement Banker's Algorithm to find safe sequence of process execution for avoidance of deadlock */

#include <stdio.h>

int main() {
  
    int n, m, i, j, k;
    int max[10][10], alloc[10][10], avail[10];

    /* Enter no of processes */
    printf("Enter number of processes: ");
    scanf("%d", &n);

    /* Enter no of resources */
    printf("Enter number of resources: ");
    scanf("%d", &m);

    /* Enter Max matrix */
    printf("\nEnter the Maximum need for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess #%d:\n", (i + 1));

        for (j = 0; j < m; j++) {
            printf("%c: ", ('A' + j));
            scanf("%d", &max[i][j]);
        }
    }

    /* Enter Allocation matrix */
    printf("\nEnter the Allocation for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess #%d:\n", (i + 1));

        for (j = 0; j < m; j++) {
            printf("%c: ", ('A' + j));
            scanf("%d", &alloc[i][j]);
        }
    }

    /* Enter Available */
    printf("\nEnter the amount of resources available with the OS:\n");
    for (i = 0; i < m; i++) {
        printf("%c: ", ('A' + i));
        scanf("%d", &avail[i]);
    }

    /* Set flag for each resource to 0 */
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    /* Calculate Need matrix */
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    /* Calculate Safe Sequence */
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    /* If the resources needed by process exceeds what is available, then the process will leave the system in an unsafe state */
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
  
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        /* Add the allocated resources to the available resources after process executes */
                        avail[y] += alloc[i][y];
                    /* Signifies that process has executed */
                    f[i] = 1;
                }
            }
        }
    }

    /* Print Safe Sequence */
    printf("Printing Safe Sequence:\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
  
    return 0;
}