#include <iostream>
#include <vector>
using namespace std;
// input is 0 to 30 as oneline suffled
//then sort whith fliping index : 0~n
vector<int> v;
int i = 0, M = 0;
void flip(int);
int main()
{
    FILE *file = fopen("input.txt", "r");
    int MAX_input = 30, t;
    while (!feof(file))
    {
        fscanf(file, "%d", &t);
        if (v.size())
            if (v.at(M) < t)
                M = i;
        v.push_back(t);
        if (v.size() == MAX_input)
            break;
        fscanf(file, " ", &t);
        i++;
    }
    int sizes = v.size();
    if (v.back() != v.at(M))
    {
        flip(M);
        flip(sizes - 1);
    }
    for (int i = sizes - 2; i != 0; i--)
    {
        M = i;
        for (int j = 0; j < i; j++)
        {
            if (v.at(M) < v.at(j))
                M = j;
        }
        flip(M);
        flip(i);
    }
    for (int i = 0; i < sizes; i++)
        cout << v.at(i) << " ";
}
void flip(int point)
{
    if (point == 0)
        return;
    vector<int> temp;
    int tem;
    for (int i = 0; i <= point / 2; i++)
    {
        tem = v.at(i);
        v.at(i) = v.at(point - i);
        v.at(point - i) = tem;
    }
}