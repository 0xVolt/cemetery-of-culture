/* Code by Desh Iyer
* Program to illustrate how two processes access critical section and shared resources using Semaphores */

#include <stdio.h>
#include <unistd.h> // For sleep()
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void *thread(void *arg);

/* Start of main function */
int main() {
    sem_init(&mutex, 0, 1);
    
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, thread, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    sem_destroy(&mutex);
    
    return 0;
} /* End of main program */

void *thread(void *arg) {
    sem_wait(&mutex); // Waiting
    printf("\nEntered critical section\n");
    
    // critical section
    sleep(2);
    
    printf("\nExiting critical section\n");
    sem_post(&mutex); // Signalling
}