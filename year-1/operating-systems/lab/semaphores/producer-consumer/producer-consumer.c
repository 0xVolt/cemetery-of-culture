/* Code by Desh Iyer

* Program to demonstrate the Prosucer - Consumer problem in C using Semaphores 
  using a Menu driven program */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Global variable declaration */
int mutex = 1, fullSpaces = 0, emptySpaces, count = 0, n;

/* Function declarations */
void menu();
void produce();
void consume();
int wait(int);
int signal(int);

/* Driver function */
int main() {
    printf("How many spaces in buffer: ");
    scanf("%d", &n);

    emptySpaces = n;

    menu();
}

/* Function providing Menu driven functionality */
void menu() {
    int choice;
    
    while (true) {
        system("cls"); // Clear screen after every iteration

        /* Display menu */
        printf(
            "---- M E N U ----\n\n"
            "1. Produce\n"
            "2. Consume\n"
            "3. Exit\n"
            "\nEnter choice (1 - 3): "
        );
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (mutex == 1 && emptySpaces != 0)
                    produce();
                else
                    printf("\nBuffer full!");

                break;

            case 2:
                if (mutex == 1 && fullSpaces != 0)
                    consume();
                else    
                    printf("\nBuffer empty!");

                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again");
        }

        printf("\n");
        system("pause");
    }
}

/* Wait function */
int wait(int S) {
    S--;
    return S;
}

/* Signal Function */
int signal(int S) {
    S++;
    return S;
}

/* Function to produce to the buffer */
void produce() {
    mutex = wait(mutex);

    /* Start of Critical section */

    fullSpaces = signal(fullSpaces);
    emptySpaces = wait(emptySpaces);
    count++;

    printf("\nProducer produces item #%d", count);

    /* End of Critical section */

    mutex = signal(mutex);
}

/* Function to consume from the buffer */
void consume() {
    mutex = wait(mutex);

    /* Start of Critical section */
    
    fullSpaces = wait(fullSpaces);
    emptySpaces = signal(emptySpaces);

    printf("\nConsmumer consumes item #%d", count);
    count--;

    /* End of Critical section */

    mutex = signal(mutex);
}
