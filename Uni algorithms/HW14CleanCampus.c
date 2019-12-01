/**
 * find shortest length for cover all point
 * from (0,0)
 * to bind need 1 m
 * 
 * test input
 * 1
 * 
 * 4
 * 1.0 1.0
 * -1.0 1.0
 * -1.0 1.0
 * 1.0 -1.0
 * 
 * output 10.83
 *  *-------------*
 *  |   _- * -_   |
 *  *.-'       `-.*
 * 
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int length;
    int seta;
} Point;
typedef struct Heap
{
    void *data;
    size_t elementSize;
    int dataLength;
} Heap;
//define Heap functions
void *popHeap(Heap *heap);
void clearHeap(Heap *heap);
void insertToHeap(Heap *heap, void *data, int (*compareTo)(void *, void *));
void insertPoint(Heap *heap, int x, int y);
int compareTo();
int main()
{
    Heap PointHeap;
    int caseCount, PointCount, tempA, tempB;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &caseCount);
    while (caseCount != 0)
    {
        caseCount--;
        fscanf(fptr, "%d", &PointCount);

        while (PointCount != 0)
        {
            PointCount--;
            fscanf(fptr, "%d %d", &tempA, &tempB);
            insertPoint(&PointHeap, tempA, tempB);
        }

        // for enter new data we need to clear heap
        clearHeap(&PointHeap);
    }
}
void insertToHeap(Heap *heap, void *data, int (*compareTo)(void *, void *))
{
    
}
void *popHeap(Heap *heap)
{

}
int compareTo(void *firstElement, void *secondElement)
{
    return ((Point *)firstElement)->length - ((Point *)secondElement)->length;
}
void clearHeap(Heap *heap)
{
    free(heap->data);
    heap->data = NULL;
    heap->dataLength = 0;
}
void insertPoint(Heap *heap, int x, int y)
{
    Point *a = (Point *)malloc(sizeof(Point));
    //TODO: Calc length, seta
    insertToHeap(heap, a, compareTo);
}