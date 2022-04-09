// Code by Desh Iyer
// 500081889

// Code to calculate vulnerable time in the scenario of error detection using conditional statements to check whether the collision occurs in between frames using vulnerable time and transmission time

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int k = 0;
    double propagationTime;

    printf("Enter the propagation time: ");
    scanf("%lf", &propagationTime);

    while (k < 15) {
        double vulnerableTime;
        int temp;

        temp = (2 * propagationTime) + 1;

        srand(time(0));

        vulnerableTime = rand() % temp;
    
        if (vulnerableTime > temp) {
            printf("\nNo collision occurred!");
            
            break;
        } else if (vulnerableTime == temp) {
            int flag = rand() % 2;

            if (flag == 0) {
                printf("\nNo collision occurred!");
            
                break;
            } else {
                k++;
                printf("\nCollision occurs!");
            }
        }
    }
}