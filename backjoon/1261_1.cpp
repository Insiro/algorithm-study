#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
    int N, M, temp;
    scanf("%d %d", &M, &N);
    vector<int> table(M);
    scanf("%1d", &table[0]);
    for (int i = 1; i < M; i++)
    {
        scanf("%1d", &table[i]);
        table[i] += table[i - 1];
    }
    N--;
    while (N)
    {
        for (int i = 0; i < M; i++)
        {
            scanf("%1d", &temp);
            if (!i)
                table[i] += temp;
            else if (table[i - 1] > table[i])
                table[i] += temp;
            else
                table[i] = table[i - 1] + temp;
        }
        N--;
    }
    printf("%d", table[M - 1]);
    return 0;
}