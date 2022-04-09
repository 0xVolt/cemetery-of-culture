/*
Akshit Gandotra
Question 2 (Lab)
Design a structure ‘subject’ to store the details of the subject like subject name and subject code. Using structure pointer allocate memory for the structure dynamically so as to obtain details of ‘n’ subjects using for loop.
*/

#include <stdio.h>
#include <stdlib.h>

struct subject  // structure initialization
{
    char SubName[50];
    char SubCode[50];
};

int main()
{
    struct subject *details;
    int n;
    printf("Enter the Number of Subjects\n");
    scanf("%d", &n);
    details=(struct subject * )malloc(n * sizeof (struct subject));  // dynamic memory allocation
    for(int i = 0; i < n; i++)  // user input
    {
        printf("Enter Name of the Subject and Subject Code.\n");
        scanf("%s %s", (details + i)->SubName, (details + i)->SubCode);
    }
    printf("SubjectName \t\t SubjectCode.\n");
    for(int i = 0; i < n; i++)  // printing subject name and code
    {
        printf("%s \t\t %s \n", (details + i)->SubName, (details + i)->SubCode );
    }
    free(details);
}