#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct quenPos QPOS;
struct quenPos
{
    int x, y;
};
int checkPosition(QPOS *Quens, int usedQuenCount, int PosX, int PosY);
int computeSmallCase(int boardSize, int QuenCount, QPOS *Quens, int usedQuenCount);
int computeCase(int boardSize, int QuenCount);
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int boardSize, QuenCount;
    fscanf(fptr, "%d %d", &boardSize, &QuenCount);
    while (boardSize != 0 && QuenCount != 0)
    {
        printf("asd %d\n", computeCase(boardSize, QuenCount));
        fscanf(fptr, "%d %d", &boardSize, &QuenCount);
    }
}
int computeCase(int boardSize, int QuenCount)
{
    QPOS *Quens = (QPOS *)malloc(sizeof(QPOS) * (QuenCount + 1));
    for (int i = 0; i < QuenCount + 1; i++)
    {
        Quens[i].y = Quens[i].x = -1;
    }
    return computeSmallCase(boardSize, QuenCount, Quens, 0);
}
int checkPosition(QPOS *Quens, int usedQuenCount, int PosX, int PosY)
{
    if (usedQuenCount == 0)
    {
        return 1;
    }
    for (int i = 1; i < usedQuenCount; i++)
    {
        if (abs(Quens[i].x - PosX) == abs(Quens[i].y - PosY))
        {
            return 0;
        }
    }
    return 1;
}
// int computs(){
//     if(isLast()){
//         return availables;
//     }
//     else{
//         if(available()){

//         }
//         else{ 
//             return 0;
//         }
//     }
// }
int computeSmallCase(int boardSize, int QuenCount, QPOS *Quens, int usedQuenCount)
{
    if (usedQuenCount == QuenCount)
    {
        return 0;
    }
    int re = 0;
    for (int x = Quens[usedQuenCount].x; x < boardSize; x++)
    {
        if (x < 0)
        {
            continue;
        }
        for (int y = Quens[usedQuenCount].y; y < boardSize; y++)
        {
            if (y < 0 || (x==Quens[usedQuenCount].x&&y==Quens[usedQuenCount].y))
            {
                continue;
            }
            if (checkPosition(Quens, usedQuenCount, x, y))
            {
                Quens[usedQuenCount + 1].x = x;
                Quens[usedQuenCount + 1].y = y;

                if (usedQuenCount+1 == QuenCount)
                {
                    re++;
                }
                else
                {
                    re += computeSmallCase(boardSize, QuenCount, Quens, usedQuenCount + 1);
                }
            }
        }
    }

    printf("%d %d\n", usedQuenCount, re);
    return re;
}
