#include <stdio.h>
#define size 10
int main()
{
    int table[size][size];
    int timet[size], go[size],come[size];
    int N, M, X, t1, t2, time;
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < size; i++)
    {
        timet[i] = NULL;
        for (int j = 0; j < size; j++)
            table[i][j] = NULL;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", t1, t2, time);
        if (table[t1][t2] == NULL || table[t1][t2] > time)
        {
            min[t1] = time;
            table[t1][t2] = time;
        }
    }
}