#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//test_input
// 6008 1300
// 6000 2100
// 500 2000
// 1000 4000
// 1100 3000
// 6000 2000
// 8000 1400
// 6000 1200
// 2000 1900
struct data
{
    int num;
    int W;
    int S;
};
typedef struct data lt;

bool inputCompare(lt a, lt b)
{
    if (a.W == b.W)
    {
        return a.S > b.S;
    }
    return a.W < b.W;
}

int main()
{
    //input
    FILE *fptr = fopen("input.txt", "r");
    vector<lt> inputData;
    int inputCount = 1;
    lt temp;
    while (!feof(fptr))
    {
        temp.num = inputCount++;
        fscanf(fptr, "%d %d", &(temp.S), &(temp.W));
        inputData.push_back(temp);
    }
    sort(inputData.begin(), inputData.end(), inputCompare);

    //dp
    int max_len[1000], templit[1000];
    int max = 0, max_pos = 0;
    for (int k = 0; k < inputData.size(); k++)
    {
        max_len[k] = 1;
        templit[k] = 0;
        for (int j = 0; j < k; j++)
            if (inputData[j].S > inputData[k].S && inputData[j].W < inputData[k].W)
                if (max_len[j] + 1 > max_len[k])
                {
                    max_len[k] = max_len[j] + 1;
                    templit[k] = j;
                    if (max <= max_len[k])
                    {
                        max = max_len[k];
                        max_pos = k;
                    }
                }
    }
    //tracking
    cout << max << endl;
    stack<int> answer_lit;
    int i = max_pos;
    for (int i = max_pos; i > 0; i = templit[i])
        answer_lit.push(i);
    cout << inputData.begin()->num << endl;
    while (answer_lit.size() != 0)
    {
        cout << inputData[answer_lit.top()].num << endl;
        answer_lit.pop();
    }
    return 0;
}