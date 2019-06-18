#include <stdio.h>
#include <math.h>
//어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다.
// N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
void han(int);
int resault = 0;
int main()
{
    int N;
    scanf("%d", &N);
    for (int k = 1; k <= N; k++)
    {
        han(k);
    }
    printf("%d", resault);
}
void han(int num)
{
    int t[3], p = num;
    t[0] = num % 10;
    num /= 10;
    t[1] = num % 10;
    num /= 10;
    t[2] = num % 10;
    if (t[2] != 0)
    {
        if (t[2] - t[1] != t[1] - t[0])
            return;
    }
    resault++;
}