#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30
void bubblesort(int *array, const int size);
void swap(int *, int *);
int main()
{
    srand((unsigned)time(NULL));
    int a[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = rand() % 100;
    }
    int i;
    puts("Data items in original order");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", a[i]);
    }
    bubblesort(a, MAX);
    puts("\nData items  in ascend sorting order");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

void bubblesort(int *array, const int size)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (array[i] > array[j])
                swap(&array[i], &array[j]);
        }
    }
}
void swap(int *s, int *b)
{
    int temp = *s;
    *s = *b;
    *b = temp;
}