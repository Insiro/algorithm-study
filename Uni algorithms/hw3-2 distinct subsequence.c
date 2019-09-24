#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//test_input
// 2
// babgbag
// bag
// rabbbit
// rabbit
//Num of str2 that can find from 1st str as sequential
int main()
{
    int N, l1, l2;
    char str1[101], str2[102];
    int table[102][102];

    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &N);
    for (int k = 0; k < N; k++)
    {
        fscanf(fptr, "%s", str2);
        fscanf(fptr, "%s", str1);
        l1 = strlen(str1);
        l2 = strlen(str2);
        for (int i = 0; i < l1 + 1; i++)
            for (int j = 0; j < l2 + 1; j++)
                table[i][j] = 0;
        for (int i = 1; i < l1 + 1; i++)
            for (int j = 1; j < l2 + 1; j++)
            {
                if (i == 1)
                    if (str1[i - 1] == str2[j - 1])
                        table[i][j] = table[i][j - 1] + 1;
                    else
                        table[i][j] = table[i][j - 1];
                else if (str1[i - 1] == str2[j - 1] && str1[i - 1] != '\0')
                    table[i][j] = table[i][j - 1] + table[i - 1][j - 1];
                else
                    table[i][j] = table[i][j - 1];
            }
        printf("%d\n", table[l1][l2]);
    }
}