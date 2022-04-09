/* ONLY WORKS WITH LINUX */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* #include <sys/wait.h> */
#include <unistd.h>

int main() {
    int pid, i;

    printf("Enter value of i: ");
    scanf("%d", &i);

    pid = getpid();
    pid = fork();

    if (pid == 0) {
        printf("The value of i: %d", i);
        i += 10;
        printf("\nThe value of i: %d", i);
        printf("\nChild process terminated!\n");
        exit(0);
    }
    else {
        wait(0);
        printf("\nThe value of i: %d", i);
        printf("\nParent process executed!\n");
    }

    return 0;
}
