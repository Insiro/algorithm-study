//가지고 있는 보석중 을 박스에 모두 넣는데 필요한 박스의 금액과 수량 : 상자 가격
//input
// 43
// 1 3 (cost, mount)
// 2 4
// 40
// 5 9
// 5 12
// 0
// output
// 13 1
// failed 답 : 2개

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main()
{
    FILE *fptr = fopen("input.txt", "r");
    int N, l, outer, c, t;
    int line[2][2], r[2];
    int min, arr[2];
    float avg[2];
    int p;
    while (1)
    {
        fscanf("%d", &N);
        if (!N)
            break;
        // read input line
        fscanf(fptr, "%d %d", &line[0][0], &line[0][1]);
        avg[0] = line[0][0] / line[0][1];
        fscanf(fptr, "%d %d", &line[1][0], &line[1][1]);
        avg[1] = line[1][0] / line[1][1];

        l = lcm(line[0][1], line[1][1]);
        c = (avg[0] < avg[1]) ? 0 : 1;
        t = N % l;
        r[c] = (N - t) / line[c][1];
        //lest daata : t dp
        min = NULL;
        p = t / line[0][1];
        for (int i = 0; i * line[0][1] < p; i++)
        {
            if ((t - i * line[0][1]) % line[1][1])
                continue;
            if (min == NULL)
            {
                min = i * line[0][0] + ((t - i * line[0][1]) / line[1][1]) * line[1][0];
                continue;
            }
            
        }
    }
}