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
typedef struct position
{
    float x, y;
} node;
float calcLangth(node *v, int a, int b);
int isLinked(int, int, int linked[]);
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    node *vertaxs;
    int N, i, j, minPosition, *link;
    fscanf(fptr, "%d", &N);
    float length[N][N], min, sum = 0;
    link = (int *)malloc(sizeof(int) * N);
    vertaxs = (node *)malloc(sizeof(node) * N);
    // input all nodes
    for (i = 0; i < N; i++)
    {
        fscanf(fptr, "%f %f", &(vertaxs[i].x), &(vertaxs[i].y));
        link[i] = i;
    }
    // calculate all distance between each nodes
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            length[i][j] = calcLangth(vertaxs, i, j);
    //find minimum length
    for (int i = 0; i < N; i++)
    {
        min = 0;
        //find nearest index
        for (int j = 0; j < N; j++)
        {
            if (link[j] == j || i == j)
                continue;
            if (isLinked(i, j, link))
                continue;
            // find minimum link
            if (min == 0 || min > length[i][j])
            {
                min = length[i][j];
                minPosition = j;
            }
        }
        // link with nearset node
        link[i] = minPosition;
        sum += min;
    }
    printf("%f", sum);
}
int isLinked(int f, int s, int linked[])
{
    for (int _f = f; _f != linked[_f]; _f = linked[_f])
        if (_f == s)
            return 1;
    return 0;
}
float calcLangth(node *v, int a, int b)
{
    return (a == b) ? 0 : sqrt(pow(v[a].x - v[b].x, 2) + pow(v[a].y - v[b].y, 2));
}
