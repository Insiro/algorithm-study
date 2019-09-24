#include <iostream>
#include <vector>

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
    vector<vector<int>> table(point.size(), vector(point.size(), 0));
    
}