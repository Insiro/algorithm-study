#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int table[7][7];
    table[4][1] = table[2][0] = table[1][4] = table[0][2] = 4;
    table[3][0] = table[0][3] = 13;
    table[1][0] = table[0][1] = 7;
    table[4][0] = table[0][4] = 8;
    table[5][2] = table[4][3] = table[3][4] = table[2][5] = 9;
    table[5][3] = table[3][5] = 11;
    table[5][4] = table[4][5] = 10;
    table[6][4] = table[4][6] = 14;
    table[5][6] = table[6][5] = 3;
    
}