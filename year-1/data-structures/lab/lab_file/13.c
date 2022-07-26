#include <stdio.h>
#define size 10
int arr[size];
void init()
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}
void insert(int value)
{
    int key = value % size;

    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already!\n", key, arr[key]);
        printf("Unable to insert %d\n", value);
    }
}
void print()
{
    int i;
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}
int main()
{
    init();
    insert(5000423);
    insert(5000425);
    insert(5000996);
    insert(5000864);
    insert(5000709);
    insert(5000632);
    insert(5000280);
    insert(5000101);
    insert(5000377);
    insert(5000558);
    printf("Hash table\n");
    print();
    printf("\n");
    return 0;
}
