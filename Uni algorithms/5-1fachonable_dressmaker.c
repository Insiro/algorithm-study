/**
 input test
 mount of sample case 
 >space 
 count - works
 time, panelty - 시작하기 까지 시간 1당의 패널티
 총 패널티가 최소가 되도록!
input eg)
1

4
3 4
1 1000
2 2
5 5

output 2 1 3 4
 **/
#include <stdio.h>
#include <stdlib.h>
#define max 2 ^ 32 - 1
struct datas
{
    int t, p, posi;
    struct datas *next;
};
typedef struct datas trip;
trip make_trip(int, int, int);
int compareto_trip(trip *, trip *);
void trip_sort();
void push_back(int, int, int);
trip *head;
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL)
        exit(-1);
    int M, N, a, b;
    head = NULL;
    fscanf(fptr, "%d", &M);
    for (int i = 0; i < M; i++)
    {
        fscanf(fptr, "%d", &N);
        for (int i = 0; i < N; i++)
        {
            fscanf(fptr, "%d %d", &a, &b);
            push_back(a, b, i);
        }
        trip_sort();

        trip *point = head, *temp;
        while (point != NULL)
        {
            printf("%d ", point->posi + 1);
            temp = point;
            point = temp->next;
            free(temp);
        }
        head = NULL;
        printf("\n");
    }
}
void push_back(int t, int p, int posi)
{
    static trip *final;
    if (head == NULL)
    {
        head = (trip *)malloc(sizeof(trip));
        final = head;
        head->t = t;
        head->p = p;
        head->posi = posi;
        head->next = NULL;
        return;
    }
    final->next = (trip *)malloc(sizeof(trip));
    final = final->next;
    final->t = t;
    final->p = p;
    final->posi = posi;
    final->next = NULL;
}
int compareto_trip(trip *t1, trip *t2)
{
    float a = (float)t1->p / t1->t;
    float b = (float)t2->p / t2->t;
    return (a == b) ? t2->t < t1->t : a < b;
}
void trip_sort()
{
    int a, b, c;
    for (trip *p1 = head; p1->next != NULL; p1 = p1->next)
        for (trip *p2 = p1->next; p2 != NULL; p2 = p2->next)
            if (compareto_trip(p1, p2))
            {
                //temp
                a = p1->p;
                b = p1->t;
                c = p1->posi;
                //swap1
                p1->p = p2->p;
                p1->t = p2->t;
                p1->posi = p2->posi;
                //swap2
                p2->p = a;
                p2->t = b;
                p2->posi = c;
            }
}
