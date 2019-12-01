/**
 * test input
 * 1    //count of testCase

 * 4   // Count of pins
 * 1.0 1.0
 * -1.0 1.0
 * -1.0 -1.0
 * 1.0 -1.0
 * 
 * output 10.828426
 * 2(length for bind)+ shortest line that start from 0 to 0
 * **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define true 1
#define false 0

int MAX = 2 ^ 31 - 1;
typedef struct Point
{
    float x;
    float y;
    float used;
} Point;
float calculateDegree(Point point1, Point point2);
int findNextPont(int ankerPoint, Point *points, Point *usedPoints, int pointCount);
float calculateDistance(Point point1, Point point2);
int main()
{
    const Point point0 = {0, 0, 0};
    FILE *fptr = fopen("input.txt", "r");
    int testCount;
    double length;
    fscanf(fptr, "%d", &testCount);
    while (testCount)
    {
        testCount--;
        int pointCount, usedCount = 0;
        fscanf(fptr, "%d", &pointCount);
        Point *points = (Point *)malloc(sizeof(Point) * pointCount);
        for (int i = 0; i < pointCount; i++)
        {
            fscanf(fptr, "%f %f", &(points[i].x), &(points[i].y));
            points[i].used = 0;
        }
        Point *usedPoints = (Point *)malloc(sizeof(Point) * (pointCount + 1));
        usedPoints[0].x = usedPoints[0].y = 0;
        length = 0;
        while (true)
        {
            int closestPoint = findNextPont(usedCount, points, usedPoints, pointCount);
            if(closestPoint == pointCount)
                closestPoint = 0;
            float x = points[closestPoint].x, y = points[closestPoint].y;
            if (x == 0 && y == 0||usedCount==pointCount)
            {
                break;
            }
            usedCount++;
            usedPoints[usedCount].x = x;
            usedPoints[usedCount].y = y;
            points[closestPoint].used = 1;
        }
        free(points);
        length = calculateDistance(point0, usedPoints[2]);
        for (int i = 2; i < usedCount; i++)
        {

            length += calculateDistance(usedPoints[i], usedPoints[i + 1]);
        }
        length+=calculateDistance(usedPoints[usedCount],usedPoints[1])+calculateDistance(usedPoints[0],usedPoints[1]);
        printf("%f\n",length+2);
        free(usedPoints);
        return 1;
    }
}
float calculateDistance(Point point1, Point point2)
{
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
float calculateDegree(Point point1, Point point2)
{
    float differenceX = point1.x - point2.x;
    float differenceY = point1.y - point2.y;
    float miniDgree = fabs(differenceY) / (fabs(differenceX) + fabs(differenceY));
    if ((differenceY == 0 && differenceX == 0) || miniDgree <= 1)
    {
        assert(true);
    }
    // deta y / deta x+deta y
    if (differenceX < 0)
    {
        if (differenceY > 0)
        {
            miniDgree = 4 - miniDgree;
        }
    }
    else
    {
        if (differenceY < 0)
        {
            miniDgree = 2 - miniDgree;
        }
        else
        {
            miniDgree = 2 + miniDgree;
        }
    }
    return miniDgree * 90;
}
int findNextPont(int ankerPoint, Point *points, Point *usedPoints, int pointCount)
{
    float degree1 = calculateDegree(usedPoints[ankerPoint], points[0]), degree2;
    int nextPoint = pointCount;
    for (int i = 1; i < pointCount; i++)
    {
        if ((i == ankerPoint) || (points[i].used == 1))
        {
            continue;
        }
        degree2 = calculateDegree(usedPoints[ankerPoint], points[i]);
        if (degree1 < degree2)
        {
            degree1 = degree2;
            nextPoint = i;
        }
    }
    return nextPoint;
}