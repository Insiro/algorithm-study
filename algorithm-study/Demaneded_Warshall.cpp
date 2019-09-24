#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;
int main()
{
    vector<pair<char, int>> point;
    point.push_back(make_pair('A', 0));
    point.push_back(make_pair('B', 1));
    point.push_back(make_pair('C', 2));
    point.push_back(make_pair('D', 3));
    point.push_back(make_pair('E', 4));
    point.push_back(make_pair('F', 5));
    point.push_back(make_pair('G', 6));
    point.push_back(make_pair('H', 7));
    point.push_back(make_pair('I', 8));
    point.push_back(make_pair('J', 9));
    point.push_back(make_pair('K', 10));
    vector<vector<int>> table(point.size(), vector<int>(point.size(), 0));
    table[0][1] = table[0][2] = table[0][3] = table[3][2] = table[3][5] = table[4][0] = table[5][4] = 1;
    table[5][1] = table[6][3] = table[6][9] = table[7][6] = table[7][8] = table[8][6] = table[9][8] = table[9][5] = table[9][10] = table[10][5] = 1;
    for (int i = 0; i < point.size(); i++)
    {
        for (int j = 0; j < point.size(); j++)
            cout << " " << table[i][j];
        cout << endl;
    }
    cout << "before Warshall table" << endl
         << "--------------" << endl;
    char start, ends;
    int point_start = -1, point_end = -1;
    cout << "input start point : ";
    cin >> start;
    cout << endl
         << "input end point : ";
    cin >> ends;
    cout << endl;
    start = toupper(start);
    ends = toupper(ends);
    for (int i = 0; i < point.size() || (point_end != -1 && point_start != -1 && point_start == point_end); i++)
    {
        if (start == point[i].first)
            point_start = point[i].second;
        if (ends == point[i].first)
            point_end = point[i].second;
    }

    for (int i = 0; i < point.size(); i++)
    {
        for (int j = 0; j < point.size(); j++)
        {
            if (table[i][j])
                for (int k = 0; k < point.size(); k++)
                    if (table[j][k])
                        table[i][k] = 1;
        }
    }
    cout << "Warshall table" << endl;
    for (int i = 0; i < point.size(); i++)
    {
        for (int j = 0; j < point.size(); j++)
            cout << " " << table[i][j];
        cout << endl;
    }
    cout << "----result------" << endl
         << "you can";
    if (table[point_start][point_end] != 1)
        cout << " not";
    cout << " go " << ends << " , form " << start << endl;
}