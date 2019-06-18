#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
    int N, M, max = (1 << 30) - 1, p, i = 0, root = 0, t;
    scanf("%d %d", &M, &N);
    vector<vector<int>> table(N, vector<int>(M));
    vector<vector<int>> table2(N, vector<int>(M, max));
    vector<int> que1(1, 0);
    vector<int> que2(1, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &table[i][j]);
    table2[0][0] = 0;
    while (!que1.empty())
    {
        while (i < que1.size())
        {
            p = 4;
            if (que1[i])
            {
                t = que1[i] - 1;
                if (table[t][que2[i]] <= root)
                {
                    if (table2[t][que2[i]] > table2[que1[i]][que2[i]])
                    {
                        que1.push_back(t);
                        que2.push_back(que2[i]);
                        table2[t][que2[i]] = table2[que1[i]][que2[i]] + table[t][que2[i]];
                    }
                }
                else
                    p--;
            }
            if (que2[i])
            {
                t = que2[i] - 1;
                if (table[que1[i]][t] <= root)
                {
                    if (table2[que1[i]][t] > table2[que1[i]][que2[i]])
                    {
                        table2[que1[i]][t] = table2[que1[i]][que2[i]] + table[que1[i]][t];
                        que1.push_back(que1[i]);
                        que2.push_back(t);
                    }
                }
                else
                    p--;
            }
            t = que1[i] + 1;
            if (t != N)
            {
                if (table[t][que2[i]] <= root)
                {
                    if (table2[t][que2[i]] > table2[que1[i]][que2[i]])
                    {
                        table2[t][que2[i]] = table2[que1[i]][que2[i]] + table[t][que2[i]];
                        que1.push_back(t);
                        que2.push_back(que2[i]);
                    }
                }
                else
                    p--;
            }
            t = que2[i] + 1;
            if (t != M)
            {
                if (table[que1[i]][t] <= root)
                {
                    if (table2[que1[i]][t] > table2[que1[i]][que2[i]])
                    {
                        table2[que1[i]][t] = table2[que1[i]][que2[i]] + table[que1[i]][t];
                        que1.push_back(que1[i]);
                        que2.push_back(t);
                    }
                }
                else
                    p--;
            }
            if (p == 4)
            {
                que1.erase(que1.begin());
                que2.erase(que2.begin());
            }
            else
                i++;
        }
        root++;
        i = 0;
    }
    printf("%d", table2[N - 1][M - 1]);
    return 0;
}