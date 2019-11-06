
/**
 * test case
 * input
 * 1 test case
 * 3 도시수
 * seoul : 도시이름
 * suwon
 * daejeon
 * 3 차편
 * 2 경유지수
 * 0949 seoul 
 * 1006 suwon
 * 2
 * 1325 Seoul
 * 1550 Daejeon
 * 2
 * 1205 suwon
 * 1411 daejeon
 * 0800 가장빠른 출발시간
 * seoul 출발도시
 * daejeon 도착도시
 * 
 * output
 * departure 0949 seoul
 * arrival 1411 daejeon
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct city
{
    char name[100];
    int position;
};
struct edge
{
    int start, end;
    int time;
};
int findPosition(struct city *, char *);
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int N, size, cases, nt, te, nowtime, pretime, freP, nowP, allsize;
    char fre[100], now[100];
    fscanf(fptr, "%d", &N);
    struct city *city;
    struct edge *edge;
    for (int i = 0; i < N; i++)
    {
        fscanf(fptr, "%d", &size);
        city = (struct city *)malloc(sizeof(struct city) * size);
        for (int i = 0; i < N; i++)
        {
            fscanf(fptr, "%s", &(city[i].name));
            city[i].position = i;
        }
        fscanf(fptr, "%d", &size);
        size = allsize;
        edge = (struct edge *)malloc(sizeof(struct edge) * allsize);
        for (int i = 0; i < size; i++)
        {
            fscanf(fptr, "%d", &cases);
            for (int j = 0; j < cases; j++)
            {
                fscanf(fptr, "%d %s", &nt, now);
                nowtime = pretime;
                freP = nowP;
                nowP = findPosition(city, now);
                nowtime = (nt / 100) * 60 + nt % 100;
            }
        }
    }
}
int findPosition(struct city *city, char *name)
{
    int size = sizeof(city) / sizeof(struct city), i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(city[i].name, name) == 0)
            return i;
    }
}