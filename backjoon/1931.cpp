#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef struct dat li;
struct dat
{
    int start;
    int finish;
};
int main()
{
    int n, a, b, j = 0;
    scanf("%d", &n);
    vector<li *> list;
    li *point = (li *)malloc(sizeof(li));
    scanf("%d %d", &(point->start), &(point->finish));
    list.push_back(point);
    for (int i = 1; i < n; i++)
    {
        li *point = (li *)malloc(sizeof(li));
        scanf("%d %d", &(point->start), &(point->finish));
        for (j = 0; j < list.size(); j++)
            if (list[j]->finish - list[j]->start > point->finish - point->start)
                break;
        list.insert(list. begin() + j, point);
    }
    vector<li *> make;
    make.push_back(list[0]);
    list.erase(list.begin());
    int i = 0;
    while (!list.size())
    {
        for (j = 0; j < make.size(); j++)
            if (list[0]->finish <= make[j]->start)
            {
                if (!j)
                    make.insert(make.begin(), list[0]);
                else if (list[0]->start >= make[j - 1]->finish)
                    make.insert(make.begin() + j - 1, list[i]);
                goto con;
            }
        if (make[make.size() - 1]->finish < list[0]->start)
            make.push_back(list[0]);
    con:
        list.erase(list.begin());
    }
    printf("%d", make.size());
    return 0;
}
