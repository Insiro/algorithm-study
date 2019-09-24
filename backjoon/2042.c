#include <stdio.h>
#include <stdlib.h>
typedef struct Arr arr;
struct Arr
{
    int data;
    struct Arr *next;
};
arr *head;
int main()
{
    head = (arr *)malloc(sizeof(arr));
    arr *point = head;
    int N, M, K, a, b, c, t, sum = 0;
    scanf("%d %d %d %d", &N, &M, &K, &(point->data));
    sum += point->data;
    for (int i = 1; i < N; i++)
    {
        point->next = (arr *)malloc(sizeof(arr));
        point = point->next;
        scanf("%d", &(point->data));
        sum += point->data;
    }
    point->next = NULL;
    while (M + K)
    {
        point = head;
        scanf("%d %d %d", &a, &b, &c);
        b %= N;
        if (a == 1)
        {
            M--;
            for (t = 0; t != b; t++)
                point = point->next;
            sum += (point->data) - c;
            point->data = c;
        }
        else
        {
            K--;
            a = 0;
            if (c >= N)
            {
                a += sum;
                a *= c / N;
                c %= N;
            }
            point = head;
            for (t = 0; t < b; t++)
                point = point->next;
            for (t = 0; t < c; t++)
            {
                if (point->next == NULL)
                    point = head;
                else
                    point = point->next;
                a += point->data;
            }
            printf("%d\n", a);
        }
    }
}