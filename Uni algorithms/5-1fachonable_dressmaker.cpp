/**
 input test
 mount of sample case 
 >space 
 count - works
 time, panelty - 시작하기 까지 시간 1당의 패널티
 총 패널티가 최소가 되도록!
input eg)
1

4
3 4
1 1000
2 2
5 5

output 2 1 3 4
 **/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#define max 2 ^ 32 - 1
using namespace std;
struct datas
{
    int t, p, posi;
};
typedef struct datas trip;
trip make_trip(int, int, int);
float compareto_trip(trip, trip);
void trip_sort(vector<trip> *);
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL)
        exit(-1);
    int M, N, a, b, s, min[2];
    vector<trip> v;
    fscanf(fptr, "%d", &M);
    for (int i = 0; i < M; i++)
    {
        fscanf(fptr, "%d", &N);
        for (int i = 0; i < N; i++)
        {
            fscanf(fptr, "%d %d", &a, &b);
            v.push_back(make_trip(a, b, i));
        }
        trip_sort(&v);
        for (int i = 0; i < N; i++)
            cout << v[i].posi + 1 << " ";
        cout << endl;
        v.clear();
    }
}
trip make_trip(int a, int b, int i)
{
    trip mp = {a, b, i};
    return mp;
}
float compareto_trip(trip t1, trip t2)
{
    float a = (float)t1.p / t1.t;
    float b = (float)t2.p / t2.t;
    return (a == b) ? t2.t - t1.t : a - b;
}
void trip_sort(vector<trip> *v)
{
    int size = (*v).size();
    for (int i = 0; i < size - 1; i++)
        for (int j = i; j < size; j++)
            if (compareto_trip((*v)[i], (*v)[j]) < 0)
            {
                trip temp = (*v)[i];
                (*v)[i] = (*v)[j];
                (*v)[j] = temp;
            }
}
