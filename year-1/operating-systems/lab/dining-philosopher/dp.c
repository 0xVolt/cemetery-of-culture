/* Code by Desh Iyer 

- Program illustrating the classic Dining Phiosopher's Problem in Process Synchronization. */

#include <stdio.h>
#include <semaphore.h>

void wait(int);
void signal(int);
void philosopher(int *);

/* Driver function */
int main() {
    int chopsticks[5];  /* Array to store information about the state of each chopstick */

    /* Setting initial value for all chopsticks to be 1 
    i.e. set them all to be free */
    for (int i = 0; i < 5; i++) {
        chopsticks[i] = 1;
    }

    printf("Considering that there are 5 philosophers and 5 chopsticks, the problem is solved as follows:\n");

    philosopher(chopsticks);
} /* End of driver function */

/* Check if both chopsticks are available for the hungry philosopher */
void philosopher(int *chopsticks) {
    for (int i = 0; i < 5; i++) {    
        /* Mark two chopsticks as unavailable by setting values to 0 */
        wait(chopsticks[i]);
        wait(chopsticks[(i + 1) % 5]);

        printf("Philosopher #%d eats...\n", i);

        /* Mark two chopsticks as available by setting values back to 1 */
        signal(chopsticks[i]);
        signal(chopsticks[(i + 1) % 5]);

        printf("Philosopher #%d thinks...\n", i);
    }
} /* End of philosopher() */

/* Atomic process WAIT */
void wait(int S) {
    while (S <= 0); // Enter infinte loop if S <= 0
    
    S--;
}

/* Atomic process SIGNAL */
void signal(int S) {
    S++;
}