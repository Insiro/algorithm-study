#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE sizeof(Arr)
#define Allo (Arr *)malloc(SIZE)
typedef struct st Arr;
struct st
{
    int data;
    struct st *next;
};

Arr *head = NULL;
Arr *Left = NULL;
Arr *Right = NULL;
void hole(Arr *, int);
void merge(Arr*, int);
void devide(Arr *, int, Arr *, int);
void insert(int);
int main()
{
    int size, b;
    for (int i = 0; i < size; i++)
    {
        insert(rand() % 100);
    }
}
void insert(int data)
{
    Arr *point;
    if (head == NULL)
    {
        head = Allo;
        point = head;
    }
    else
    {
        for (point = head; point->next != NULL; point = point->next)
            ;
        point->next = Allo;
        point = point->next;
    }
    point->next = NULL;
    point->data = data;
}
void merge(Arr*start, int sizes)
{
    Arr*point=start;
    for(int i=0;i<sizes;i++){
        point=point->next;
    }
    
}
void devide(Arr *pointL, int left, Arr *pointR, int right)
{
    Arr*point=pointL;

}
void hole(Arr *start, int sizes)
{
    Arr *pointR;
    int left = sizes / 2;
    for (int i = 0; i < left; i++)
    {
        pointR = pointR->next;
    }

    hole(start, left);
    hole(pointR, sizes - left);
    devide(start, left, pointR, sizes - left);
    merge(start, sizes);
}