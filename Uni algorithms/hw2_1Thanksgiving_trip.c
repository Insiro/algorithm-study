#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fpt = fopen("input.txt", "r");
    int t, N, sum, avg, *v;
    while (!feof(fpt))
    {
        sum = 0;
        fscanf(fpt, "%d", &N);
        if (!N)
            break;
        v = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
        {
            fscanf(fpt, "%d", &v[i]);
            sum += v[i];
        }
        avg = sum / N;
        for (int i = sum = 0; i < N; i++)
            if (v[i] > avg)
                sum += (v[i] - avg) / 10 * 10;
        printf("%d\n", sum);
        free(v);
    }
}