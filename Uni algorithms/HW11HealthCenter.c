/**
 * find optimal for new hospital
 * 
 * test input
 * 1 6    number of existing health centers<100, number of intersections <500
 * 2      section number that having hospital    / f line
 * 1 2 10  intersection information : section a, section b , cost
 * 2 3 10
 * 3 4 10
 * 4 5 10
 * 5 6 10
 * 6 1 10
 * 
 * test output
 * 5   /position of new hospital
**/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define test 1
int outputTable(int intersectionCounts, void *dt)
{
    (int(*)[intersectionCounts])dt)[0][0];
    printf("if data is INT_MAX output -1\neach value is distance between sections\n");
    for (int i = 0; i < intersectionCounts; i++)
    {
        for (int j = 0; j < intersectionCounts; j++)
            printf("%d ", (((int(*)[intersectionCounts])dt)[i][j] == INT_MAX) ? -1 : ((int(*)[intersectionCounts])dt)[i][j]);
        printf("\n");
    }
    printf("--------\n");
}
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int a, b, c;
    fscanf(fptr, "%d", &a);
    const int hospitalCount = a;
    fscanf(fptr, "%d", &a);
    const int intersectionCounts = a;
    int distanceTable[intersectionCounts][intersectionCounts],
        hospitalPositions[hospitalCount],
        result[intersectionCounts][2];
    const int ti = intersectionCounts - 1;
    for (int i = 0; i < intersectionCounts; i++)
    {
        distanceTable[i][i] = distanceTable[i][i] = 0;
        result[i][0] = INT_MAX;
        for (int j = i + 1; j < intersectionCounts; j++)
            distanceTable[i][j] = distanceTable[j][i] = INT_MAX;
        if (i < hospitalCount)
            fscanf(fptr, "%d", &hospitalPositions[i]);
    }
    while (!feof(fptr))
    {
        fscanf(fptr, "%d %d %d", &a, &b, &c);
        if (distanceTable[a - 1][b - 1] > c)
            distanceTable[a - 1][b - 1] = distanceTable[b - 1][a - 1] = c;
    }
    fclose(fptr);
    test || outputTable(intersectionCounts, distanceTable); // tableTest
    // floyd warshall
    for (int i = 0; i < intersectionCounts; i++)
        for (int j = 0; j < intersectionCounts; j++)
            for (int k = 0; k < intersectionCounts; k++)
                if (distanceTable[i][k] > distanceTable[i][j] + distanceTable[j][k])
                    if (distanceTable[i][j] == INT_MAX || distanceTable[j][k] == INT_MAX)
                        continue;
                    else
                        distanceTable[k][i] = distanceTable[i][k] = distanceTable[i][j] + distanceTable[j][k];
    test || outputTable(intersectionCounts, distanceTable); // tableTest
    // find longest section from each all hospital
    for (int i = 0; i < hospitalCount; i++)
    {
        if (distanceTable[i][0] == INT_MAX)
            break;
        a = hospitalPositions[i] - 1;
        for (int j = 0; j < intersectionCounts; j++)
        {
            if (result[j][0] > distanceTable[j][a])
            {
                result[j][0] = distanceTable[j][a];
                result[j][1] = j;
            }
        }
    }
    for (int i = 0, a = 0; i < intersectionCounts; i++)
    {
        if (distanceTable[i][0] == INT_MAX)
            continue;
        if (a < result[i][0])
        {
            a = result[i][0];
            b = result[i][1];
        }
    }

    printf("result : %d", b + 1);
}