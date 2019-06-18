#include <stdio.h>
int main()
{
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    v -= b;
    a -= b;
    printf("%d", ((v % a) ? v / a + 1 : v / a));
}