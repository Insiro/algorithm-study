#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> table(N, vector<int>(M));
    vector<vector<int>> table2(N, vector<int>(M, 0));
    queue<int> que[2];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &table[i][j]);
    table2[0][0] = 1;
    que[0].push(0);
    que[1].push(0);
    while (!que[1].size())
    {
    }
    int i = 0;

    return 0;
}