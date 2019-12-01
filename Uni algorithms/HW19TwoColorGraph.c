#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define bool int
/**
 * check coloring graph with two color is able
 * use backtrace algorithm
 * testcase
 * 3   // node Count
 * 3  //edge Count
 * 0 1  //connected node
 * 1 2
 * 2 0
 *  ->not two color
 * 5
 * 4
 * 0 1
 * 0 2
 * 0 3
 * 0 4
 *  -> two color
 * **/
typedef struct Graph
{
    //int *DFSTable;
    bool *nodetable;
    int **edgeTable;
    int NodeCount;
} graph;
bool twoColoring(graph g, int nodeIndex);
bool isValiedNode(graph g, int nodeIndex, bool color);

int main()
{
    graph g;
    FILE *fptr = fopen("input.txt", "r");
    int edgeCount;
    while (!feof(fptr))
    {
        fscanf(fptr, "%d", &(g.NodeCount));
        fscanf(fptr, "%d ", &edgeCount);
        g.nodetable = (bool *)calloc(g.NodeCount, sizeof(bool));
        //g.DFSTable = (int *)calloc(g.NodeCount, sizeof(int));
        g.edgeTable = (int **)calloc(g.NodeCount, sizeof(int *));
        int startNode, targetNode;
        for (int i = 0; i < g.NodeCount; i++)
        {
            g.edgeTable[i] = (int *)calloc(g.NodeCount, sizeof(int));
        }
        for (int i = 0; i < edgeCount; i++)
        {
            fscanf(fptr, "%d %d", &startNode, &targetNode);
            g.edgeTable[startNode][targetNode] = g.edgeTable[targetNode][startNode] = 1;
        }
        if (twoColoring(g, 0) == true)
            printf("two-color\n");
        else
        {
            printf("not two-color\n");
        }
        for (int i = 0; i < g.NodeCount; i++)
        {
            free(g.edgeTable[i]);
        }
        free(g.edgeTable);
        free(g.nodetable);
    }
}
bool twoColoring(graph gt, int nodeIndex)
{
    if (nodeIndex == gt.NodeCount)
        return true;
    else if (isValiedNode(gt, nodeIndex, true) == true)
    {
        gt.nodetable[nodeIndex] = true;
        twoColoring(gt, nodeIndex + 1);
    }
    else if (isValiedNode(gt, nodeIndex, false) == true)
    {
        gt.nodetable[nodeIndex] = false;
        twoColoring(gt, nodeIndex + 1);
    }
    else
    {
        return false;
    }
}
bool isValiedNode(graph gv, int nodeIndex, bool color)
{
    for (int i = 0; i < nodeIndex; i++)
    {
        if (gv.nodetable[i] == color && gv.edgeTable[i][nodeIndex] == 1)
        {
            return false;
        }
    }
    return true;
}