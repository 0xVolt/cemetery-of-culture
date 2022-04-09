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

    srand(time(0));
    while (k < 15) {
        double vulnerableTime;
        int temp, flag;

        temp = (2 * propagationTime) + 1;

        vulnerableTime = rand() % temp;

        printf("\n\nk: %d | Vulnerable time: %.1lf | Propagation time: %.1lf", k, vulnerableTime, propagationTime);
    
        if (vulnerableTime > temp) {
            printf("\nNo collision occurred!");
            
            break;
        } else if (vulnerableTime == temp) {
            flag = rand() % 2;

            if (flag == 0) {
                printf("\nNo collision occurred!");
            
                break;
            } else {
                k++;
                printf("\nCollision occurs!");
            }
        } else {
            k++;
            printf("\nCollision occurs!");
        }
    }
}