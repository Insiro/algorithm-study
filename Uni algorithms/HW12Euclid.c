/** n = ax + by
 * output 
 * input n, x,y
 * 
 * testcase
 * input  (a, b)
 * 4 6
 * 17 17
 * 
 * output   (x, y,d)
 * -1 1 2
 * 0 1 17
 **/
#include <stdio.h>
/**
 * d = gcd(a,b) = gcd(b, a mod b)
 * d = ax + by
 * d = bx' + (a mod b) y'
 *   = bx' + (a - floor(a/b)b )y'
 *   = bx' + ay' - floor(a/b)by'
 *   = ay' + b(x- floor(a/b))y'
 *   = ax + by
 *  -> x = y' , y = x-floor(a/b)y'
**/
int gcd(int a, int b, int *x, int *y);
int main()
{
    int a, b, n, d, x, y;
    FILE *fptr = fopen("input.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%d %d", &a, &b);
        d = gcd(a, b, &x, &y);
        if (d)
            printf("%d %d %d\n", x, y, d);
        else
            printf("No answer\n");
    }
    fclose(fptr);
}
int gcd(int a, int b, int *x, int *y)
{
    if (!(a || b))
        return 0;
    int _a = a, _b = b, d;
    while (_a % _b)
    {
        d = _a % _b;
        _a = _b;
        _b = d;
    }
    d = (_b > 0) ? _b : -_b;
    *x = (a >= b) ? 1 : -1;
    *y = (d - a * *x) / b;
    return d;
}