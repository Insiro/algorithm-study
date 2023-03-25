---
title : 젊은 날의 생이여
id : 18866
platform : 백준
url : https://www.acmicpc.net/problem/18866
date : 2023-03-25
time : 
state : fail
---
# 문제
욱제는 입대를 앞두고 <이등병의 편지>를 부르고 있다.

_… 이제 다시 시작이다 젊은 날의 생이여 …_ 

그런데 과연 욱제에게 젊은 날이 있었을까? 욱제에게 젊은 날이 있었는지 알아보자.

먼저, N년간 욱제의 행복도와 피로도가 주어진다. 행복도와 피로도는 양의 실수 값을 가진다. 어떤 1 ≤ K < N에 대해 1, 2, …, K년은 욱제의 젊은 날이고, K + 1, K + 2, …, N년은 욱제의 늙은 날이다.

젊은 날과 늙은 날은 다음의 조건을 만족한다:

-   임의의 젊은 날의 행복도는 임의의 늙은 날의 행복도보다 높다.
-   임의의 젊은 날의 피로도는 임의의 늙은 날의 피로도보다 낮다.

욱제는 자신의 행복도와 피로도를 이용하여 자신의 젊은 날을 알아보려 한다. 하지만, 일부 값이 누락되었다. 욱제를 도와주자.
## 입력
첫째 줄에 N이 주어진다.

둘째 줄부터 N개의 줄에는 두 **정수** ui, vi (1 ≤ i ≤ N)가 주어진다. ui, vi가 1 이상일 경우 각각 i년의 행복도와 피로도를 나타내며, 0인 경우에는 값이 누락되었음을 의미한다.

5
행복도1, 피로도1
행복도2, 피로도2
행복도3, 피로도3
행복도4, 피로도4
행복도5, 피로도5

## 출력
욱제의 젊은 날이 될 수 있는 최대 기간, 즉 문제의 조건을 만족할 수 있는 최대의 1 ≤ K < N을 출력한다. 단, 이러한 K가 없을 경우, -1을 출력한다
## 제한
-   2 ≤ N ≤ 1,000,000
-   0 ≤ ui, vi ≤ 109
-   주어지는 N개의 행복도 중 0이 아닌 값은 모두 다르다.
-   주어지는 N개의 피로도 중 0이 아닌 값은 모두 다르다.



# code
```python
from sys import maxsize
from case_checker import Checker


def solution(arr):
    positive_arr = get_positive_arr(arr)
    negative_arr = get_negative_arr(arr)
    answer = 0

    for idx in range(len(positive_arr) - 1):
        positive = positive_arr[idx]
        negative = negative_arr[idx]
        if negative[0] >= positive[0] and negative[1] <= positive[1]:
            answer += 1
    return -1 if answer == 0 else answer

# 늙은 시기 비겨를 위한 list
def get_positive_arr(records):
    max_happy = records[-1][0]
    min_tiered = records[-1][1]
    if min_tiered == 0:
        min_tiered = maxsize
    positive_arr = [[max_happy, min_tiered]]
    for happy, tiered in reversed(records[1:]):
        if happy > max_happy:
            max_happy = happy
        if tiered < min_tiered:
            min_tiered = tiered
        positive_arr.append([max_happy, min_tiered])
    return list(reversed(positive_arr))


# 젊은 시기 비교를 위한 list
def get_negative_arr(records):
    max_tiered = records[0][1]
    min_happy = records[0][0]
    if min_happy == 0:
        min_happy = maxsize
    negative_arr = [[min_happy, max_tiered]]
    for happy, tiered in records[1:]:
        if happy < min_happy:
            min_happy = happy
        if tiered > max_tiered:
            max_tiered = tiered
        negative_arr.append([min_happy, max_tiered])
    return negative_arr
    
def read_input():
    N = int(stdin.readline())
    records = []
    for _ in range(N):
        input_days = [int(a) for a in stdin.readline().split(" ")]
        records.append(input_days)
    return records
checker = Checker(solution)
checker([[5, 1], [4, 2], [3, 3], [2, 5], [1, 4]], 3)
checker([[1, 1], [2, 2], [3, 3]], -1)
checker([[0, 0], [0, 0], [0, 0]], 2)


if __name__ == "__main__":
	records = read_input()
	print(solution(records), end="")
```

