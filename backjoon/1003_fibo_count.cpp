/**
 * print out the number of called
 * fibonacci(0) and fibonacci(1)
 * when using reculsive fibonacci function
 * 
 * fibo 0 is 0, and fibo 1 is 1
 *
 * input
 * Number of Case
 * test cases
 * 
 * output
 * each test case number of called 0 and 1
 * 
 * testcase
 * input 
 * 3
 * 0
 * 1
 * 3
 * output
 * 1 0
 * 0 1
 * 1 2
 * 
 * */
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, t, M = 0, r = 0, pre = 0;
    vector<pair<int, int>> test_case;
    scanf("%d", &N);
    vector<pair<int, int>> ans(N, make_pair(0, 0));
    vector<pair<int, int>>::const_iterator pos;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        test_case.push_back(make_pair(t, i));
        if (t > M)
            M = t;
    }
    for (int i = 0; i < M + 1; i++)
    {
        if (i == 1)
        {
            pre = 1;
            for (pos = test_case.begin(); pos != test_case.end(); pos++)
                if (pos->first == 1)
                    ans[pos->second] = make_pair(0, 1);
        }
        else if (i == 0)
            for (pos = test_case.begin(); pos != test_case.end(); pos++)
            {
                if (pos->first == 0)
                    ans[pos->second] = make_pair(1, 0);
            }
        else
        {
            r = pre + r;
            pre = r - pre;
            for (pos = test_case.begin(); pos != test_case.end(); pos++)
                if (pos->first == i)
                    ans[pos->second] = make_pair(r, r + pre);
        }
    }
    for (int i = 0; ans.size() - 1 > i; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    printf("%d %d", ans[ans.size() - 1].first, ans[ans.size() - 1].second);
}