/*
Akshit Gandotra
Question 10 (Practice)
Design a structure ‘student_record’ to store student details like SAP ID, enrolment number, date of registration, and date of birth. The element date of joining is defined using another structure ‘date’ to store details like day, month, and year.
*/

#include <stdio.h>
#include <string.h>

struct student_record  // structure initialization
{
   int SAPid;
   char Enrol[15];
   char DOB[15];
   char DOR[15];
}s;

struct date  // structure initialization
{ 
    int day;
    char month[15];
    int year; 
}d;

int main ()
{
    int n;
    printf("Enter the Number of Students.\n"); 
    scanf("%d", &n); 
    struct student_record Stu[n];
    struct date StuD[n];
    input (  n, Stu, StuD);  // function call to input values for the Structure
    display( n, Stu, StuD);  // function call to display the values of the Structure
}


void input(int n, struct student_record *S, struct date *D)  // function to input values for the Structure
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter SAD ID, Enrollment Number, Date of Birth, Date of Registration of Students.\n");
        scanf("%d", &S->SAPid);
        scanf("%s", S->Enrol);
        scanf("%s", S->DOB);
        scanf("%s", S->DOR);
        printf("Enter Date of Joining of Students.\n");
        scanf("%d", &D->day);
        scanf("%s", D->month);
        scanf("%d", &D->year);
        S++;
        D++;
    }
}

void display(int n, struct student_record *S, struct date *D)  // function to displa the values of the Structure
{
    printf("SAD ID\tEnrollment Number\tDate of Birth\tDate of Registration\tDate of Joining \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %s \t\t%s \t\t%s \t\t", S->SAPid, S->Enrol, S->DOB, S->DOR  );
        printf("%d %s %d \n",  D->day, D->month, D->year);
        S++; 
        D++;
    }
}