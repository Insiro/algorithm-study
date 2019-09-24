#include <iostream>
#include <set>
#include <vector>
#include <ctype.h>
using namespace std;

#define mount 11
int main()
{
    char start, end;
    vector<pair<char, char>> list;
    vector<char> que;
    list.push_back(make_pair('A', 'C'));
    list.push_back(make_pair('A', 'D'));
    list.push_back(make_pair('A', 'B'));
    list.push_back(make_pair('D', 'C'));
    list.push_back(make_pair('D', 'F'));
    list.push_back(make_pair('E', 'A'));
    list.push_back(make_pair('F', 'E'));
    list.push_back(make_pair('F', 'B'));
    list.push_back(make_pair('F', 'D'));
    list.push_back(make_pair('G', 'D'));
    list.push_back(make_pair('G', 'J'));
    list.push_back(make_pair('H', 'G'));
    list.push_back(make_pair('H', 'I'));
    list.push_back(make_pair('I', 'G'));
    list.push_back(make_pair('J', 'I'));
    list.push_back(make_pair('J', 'K'));
    list.push_back(make_pair('J', 'F'));
    list.push_back(make_pair('K', 'F'));
    cout << "input  start point : ";
    cin >> start;
    start = toupper(start);
    cout << endl
         << "input end point : ";
    cin >> end;
    cout << endl;
    end = toupper(end);
    que.push_back(start);
    set<char> s;
    s.insert(start);
    for (int i = 0; i < que.size(); i++)
        for (int j = 0; j < list.size(); j++)
            if ((list[j].first == que[i]) && (s.find(list[j].second) != s.end()))
            {
                que.push_back(list[j].second);
                s.insert(list[i].second);
            }
    if (s.find(end) == s.end())
        cout << "you can go ";
    else
        cout << "you can not go ";
    cout << end << ",from " << start;
}