#include <stdio.h>
#define size 1000000
int main()
{
    int Num[100], N, M, K, sum = 0, a, b, c, J, t;
    scanf("%d %d %d", &N, &M, &K);
    J = N - 1;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
        sum += Num[i];
    }
    while (M || K)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            b %= N;
            b = (!b) ? J : b - 1;
            M--;
            sum += Num[b] - c;
            Num[b] = c;
        }
        else
        {
            K--;
            t = c - b;
            a = (t > J) ? sum * (t) / N : 0;
            c = t + 1;
            b %= N;
            b = (!b) ? J : b - 1;
            while (c)
            {
                a += Num[b];
                b = (b == J) ? 0 : b + 1;
                c--;
            }
            printf("%d\n", a);
        }
    }
}