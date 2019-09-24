#include <iostream>
#include <vector>
#include <string>
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    vector<string> v;
    vector<int> time;
    char strTemp[100];
    int min, m = 0, n = 0, N;
    fgets(strTemp, sizeof(char) * 100, fptr);
    N = atoi(strTemp);
    for (int i = 0; i < N; i++)
    {
        fgets(strTemp, sizeof(char) * 100, fptr);
        v.push_back(strTemp);
    }
    fclose(fptr);
    for (int i = 1; i < N; i++)
    {
        int min =
            600 * (v.at(i).c_str()[0] - v.at(i - 1).c_str()[6]) +
            60 * (v.at(i).c_str()[1] - v.at(i - 1).c_str()[7]) +
            10 * (v.at(i).c_str()[3] - v.at(i - 1).c_str()[9]) +
            v.at(i).c_str()[4] - v.at(i - 1).c_str()[10];
        time.push_back(min);
        if (m < min)
        {
            m = min;
            n = i - 1;
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "Day #1: the longest nap starts at %s and will last for ", v.at(n).substr(6, 5).c_str());
    if (m / 60 != 0)
    {
        fprintf(fptr, " %d hours", m / 60);
        if (m % 10 != 0)
            fprintf(fptr, " and %d minutes", m % 60);
    }
    else
        fprintf(fptr, " and %d minutes", m % 60);
    fclose(fptr);
}