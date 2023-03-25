---
title : RGB거리 2
id : 17404
platform : 백준
url : https://www.acmicpc.net/problem/17404
date : 2023-03-25
time : 
state : pass
---
# 문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

-   1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
-   N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
-   i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
### 입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.
### 출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

# 코드
```python
from case_checker import Checker
from collections import defaultdict
import sys
from sys import maxsize

sys.setrecursionlimit(10**9)
MAX_COST = maxsize - 1000000

class Board:
    def __init__(self, N, costs) -> None:
        # start color
        self.color = 0
        self.costs = costs
        # [src][color] = value
        self.max = N - 1
        
    def reset(self, color):
        self.color = color
        self.cost_table = defaultdict(lambda: [None, None, None])

    def __str__(self) -> str:
        return str(self.costs)

def check_cost(board: Board, src, color):
    if src == board.max:
        if color == board.color and board.max != 0:
            return -1
        return board.costs[board.max][color]
    if (1 != board.max - src) and board.cost_table[src][color] != None:
        return board.cost_table[src][color]
    mins = []
    if (sub_cost := check_cost(board, src + 1, (color + 2) % 3)) != -1:
        mins.append(sub_cost)
    if (sub_cost := check_cost(board, src + 1, (color + 1) % 3)) != -1:
        mins.append(sub_cost)
    cost = board.costs[src][color]
    ret = cost + min(mins)
    board.cost_table[src][color] = ret
    return ret


def solution(board: Board):
    min_cost = MAX_COST
    for i in range(3):
        board.reset(i)
        if (cost := check_cost(board, 0, i)) < min_cost:
            min_cost = cost
    return min_cost
```


#### testcase
	```python
	#region test
	check = Checker(solution)
	case = [
	    [9, 2, 8],
	    [8, 6, 5],
	    [4, 8, 5],
	    [3, 8, 2],
	    [6, 8, 8],
	]
	check(Board(len(case), case), 19)
	case = [[26, 40, 83], [49, 60, 57], [13, 89, 99]]
	check(Board(len(case), case), 110)
	case = [[1, 100, 100], [100, 1, 100], [100, 100, 1]]
	check(Board(len(case), case), 3)
	case = [[1, 100, 100], [100, 100, 100], [1, 100, 100]]
	check(Board(len(case), case), 201)
	case = [
	    [30, 19, 5],
	    [64, 77, 64],
	    [15, 19, 97],
	    [4, 71, 57],
	    [90, 86, 84],
	    [93, 32, 91]
	]
	check(Board(len(case), case), 208)
	case = [
	    [71, 39, 44],
	    [32, 83, 55],
	    [51, 37, 63],
	    [89, 29, 100],
	    [83, 58, 11],
	    [65, 13, 15],
	    [47, 25, 29],
	    [60, 66, 19],
	]
	check(Board(len(case), case), 253)
	check(Board(1, [[1, 2, 3]]), 1)
	check(Board(3, [[0, 1, 2], [1000, 1000, 1000], [3, 4, 2]]), 1002)
	case = [
	    [10, 20, 30],
	    [10, 20, 30],
	    [10, 20, 30],
	    [10, 20, 30],
	    [10, 20, 30],
	    [10, 20, 30],
	]
	check(Board(len(case), case), 90)
	check(Board(3, [[1, 100, 100], [1, 100, 100], [100, 1, 100]]), 102)
	#endregion 
	```



# 풀이
recursive dp

cost를 `[dept][color]` 의 형식의 dict에 저장
`dept == -2` 지점에서는, 시작시 선택한 색상이 영향을 줄수 있어, 저장을 안하였음

`check_cost(board, src,color)` 현재 층에서 해당 색 기준 가장 작은 cost를 반환
