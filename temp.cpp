#include <stdio.h>
#include <vector>
using namespace std;

#define mount 11
int main()
{
    char start, end;
    vector<char[2]> list;
    list.push_back({'A', 'C'});
    list.push_back({'A', 'D'});
    list.push_back({'A', 'B'});
    list.push_back({'D', 'C'});
    list.push_back({'D', 'F'});
    list.push_back({'E', 'A'});
    list.push_back({'F', 'E'});
    list.push_back({'F', 'B'});
    list.push_back({'F', 'D'});
    list.push_back({'G', 'D'});
    list.push_back({'G', 'J'});
    list.push_back({'H', 'G'});
    list.push_back({'H', 'I'});
    list.push_back({'I', 'G'});
    list.push_back({'J', 'I'});
    list.push_back({'J', 'K'});
    list.push_back({'J', 'F'});
    list.push_back({'K', 'F'});
   printf("input start point : ");
    scanf("%d",&start);
    printf("input end point : ");
    scanf("%d",&end);
}