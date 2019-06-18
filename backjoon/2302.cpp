//https://www.acmicpc.net/problem/2302
#include <iostream>
#include <math.h>
using namespace std;
int check(int);
int main()
{
    int mount, mounts, pre, next = 0, st = 1;
    cin >> mount;
    cin >> mounts;
    for (int i = 0; i < mounts; i++)
    {
        pre = next;
        
        cin >> next;
        st *= check(next - pre - 1);
    }
    cout << st * check(mount - next);
}
int check(int m) //(m-i)!/i!*(m-2i)!
{
    int t = m / 2, r = 1;
    for (int i = 1; i <= t; i++)
    {
        int s = 1, o = m - i;
        for (int j = 0; j < i; j++) //(m-i)!/(m-2i)!=(m-i)Com(i)
            s *= o - j;
        for (int j = 2; j < i + 1; j++) //i!
            s /= j;
        r += s;
    }
    return r;
}
