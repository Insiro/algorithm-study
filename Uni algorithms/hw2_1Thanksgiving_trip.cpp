#include<stdio.h>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    FILE *fpt = fopen("input.txt", "r");
    vector<int> v;
    int l = 0, t, ts, N, cal, sum = 0, avg;
    while (!feof(fpt))
    {
        sum = 0;
        t = l;
        fscanf(fpt, "%d", &N);
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            fscanf(fpt, "%d", &ts);
            v.push_back(ts);
            l++;
            sum += ts;
        }
        avg = sum / N;
        for (int i = sum = 0; i < N; i++)
            if (v.at(t + i) > avg)
                sum += (v.at(t + i) - avg) / 10 * 10;
        printf("%d\n", sum);
    }
}