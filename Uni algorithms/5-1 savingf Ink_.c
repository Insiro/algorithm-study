/**
 * make spanning tree in matrix
 * with input edge (x, y)
 * calculate all length of tree
 * 
 * test input 
 * 3    number of node
 * 1.0 1.0  possition of nodes
 * 2.0 2.0
 * 2.0 4.0
 *  test output
 * 3.41
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 2 ^ 32 - 1
struct datas
{
    int x, y;
    struct datas *link;
};
typedef struct datas dat;
int calcDistance(dat *t1, dat *t2);

void checkVisit();

dat *head, *linkList;
int main()
{
    head = (dat *)malloc(sizeof(dat));
    dat *temp, *point;
    float min, sum, dis;
    int N, i;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d %d %d", &N, &(head->x), &(head->y));
    dat *point = head;
    for (i = 1; i < N; i++)
    {
        point->link = (dat *)malloc(sizeof(dat));
        point = point->link;
        fscanf(fptr, "%d %d %d", &N, &(head->x), &(head->y));
        point->link = NULL;
    }
    linkList = head;
    head = head->link;
    point = head;
    while (point != NULL)
    {
        dis =calcDistance(point, linkList);
        if (min < dis){
            min = dis;
        }
    }
}