---
title : 아기상어  
id : 16236
platform : 백준
url : https://www.acmicpc.net/problem/16236
date : 2023-04-08
time : None
state : pass
---
# 문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

-   더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
-   먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
-   먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
    -   거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
    -   거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.
### 입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.
둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.
-   0: 빈 칸
-   1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
-   9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

# 코드
```python
from __future__ import annotations
from collections import defaultdict


INVISIABLE = -1
VISITABLE = 0
EATABLE = 1

class Board:
    def __init__(self, size, field) -> None:
        self.size = size
        self.time = 0
        self.field = field
        
    def eatten(self, target: Point, time):
        self.time += time
        self.field[target.y][target.x] = 0

class Point:
    def __init__(self, y, x) -> None:
        self.x = x
        self.y = y

    def update(self, target: Point):
        self.x = target.x
        self.y = target.y

    def get_around(self) -> list[Point]:
        return [
            Point(self.y - 1, self.x),
            Point(self.y, self.x - 1),
            Point(self.y, self.x + 1),
            Point(self.y + 1, self.x),
        ]

    def __str__(self) -> str:
        return f"({self.y},{self.x})"

    def __lt__(self, other) -> bool:
        diffy = self.y - other.y
        if diffy != 0:
            return diffy < 0
        return self.x < other.x

class Shark(Point):
    def __init__(self, y, x) -> None:
        super().__init__(y, x)
        self.count = 0
        self.size: int = 2

    def eat(self, target: Point):
        self.count += 1
        if self.count == self.size:
            self.size += 1
            self.count = 0
        return super().update(target)
  
    def check(self, target: Point, board: Board, distance):
        arr = [[], []]  # VISITABLE, EATABLE
        for item in target.get_around():
            state = self.is_visit_fist(item, board, distance)
            if state != INVISIABLE:
                arr[state].append(item)
        return arr
  
    def move(self, board: Board):
        visited: list[Point] = [self]
        time = 1
        distances = defaultdict(lambda: defaultdict(lambda: None))
        while len(visited) != 0:
            new_visit: list[Point] = []
            eatables: list[Point] = []
            for item in visited:
                visit_arr, eat_arr = self.check(item, board, distances)
                eatables += eat_arr
                new_visit += visit_arr
            if len(eatables) != 0:
                eatables.sort()
                target = eatables[0]
                self.eat(target)
                board.eatten(self, time)
                # reset states
                distances = defaultdict(lambda: defaultdict(lambda: None))
                time = 0
                visited = [self]
            else:
                visited = new_visit
            time += 1
  
    def is_visit_fist(
        self, point: Point, board: Board, distance
    ) -> EATABLE | VISITABLE | INVISIABLE:
        if point.x == board.size or point.y == board.size or point.x < 0 or point.y < 0:
            return INVISIABLE
        visited = distance[point.y][point.x]
        if visited is None:
            fish = board.field[point.y][point.x]
            if fish == 0 or fish == self.size or fish == 9:
                distance[point.y][point.x] = True
                return VISITABLE
            if fish < self.size:
                return EATABLE
        return INVISIABLE
  
def initalize():
    from sys import stdin

    input = stdin.readline
    size = int(input())
    field = []
    sharks = Shark(0, 0)
    for i in range(size):
        line = []
        for j, value in enumerate(input().split(" ")):
            value = int(value)
            line.append(value)
            if value == 9:
                sharks.y, sharks.x = i, j
        field.append(line)
    return Board(size, field), sharks
```


#### testcase
```python
def test_cases():
# case1
board = Board(3, [[0, 0, 0], [0, 0, 0], [0, 9, 0]])
Shark(2, 1).move(board)
assert board.time == 0
# case2
board = Board(3, [[0, 0, 1], [0, 0, 0], [0, 9, 0]])
Shark(2, 1).move(board)
assert board.time == 3
# case3
board = Board(4, [[4, 3, 2, 1], [0, 0, 0, 0], [0, 0, 9, 0], [1, 2, 3, 4]])
Shark(2, 2).move(board)
assert board.time == 14
# usercase 1
board = Board(	
6,
	[
		[0, 0, 0, 0, 0, 1],
		[0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0],
		[1, 3, 0, 0, 0, 0],
		[9, 3, 0, 0, 0, 0],
	],
)
Shark(5, 0).move(board)
 assert board.time == 10
 # case4
 board = Board(
	6,
	 [
		[5, 4, 3, 2, 3, 4],
		[4, 3, 2, 3, 4, 5],
		[3, 2, 9, 5, 6, 6],
		[2, 1, 2, 3, 4, 5],
		[3, 2, 1, 6, 5, 4],
		[6, 6, 6, 6, 6, 6],
	],
)
Shark(2, 2).move(board)
assert board.time == 60
# case 5
board = Board(
	6,
	[
		[6, 0, 6, 0, 6, 1],
		[0, 0, 0, 0, 0, 2],
		[2, 3, 4, 5, 6, 6],
		[0, 0, 0, 0, 0, 2],
		[0, 2, 0, 0, 0, 0],
		[3, 9, 3, 0, 0, 1],
	],
)
Shark(5, 1).move(board)
assert board.time == 48
# case 6
board = Board(
	6,
	[
		[1, 1, 1, 1, 1, 1],
		[2, 2, 6, 2, 2, 3],
		[2, 2, 5, 2, 2, 3],
		[2, 2, 2, 4, 6, 3],
		[0, 0, 0, 0, 0, 6],
		[0, 0, 0, 0, 0, 9],
	],
)
Shark(5, 5).move(board)
assert board.time == 39
# endregion
```






# 풀이

필드에 있는 모든 물고기를 먹고싶음.
상어는 한번에 한칸만 움직일수 있음.
-상하좌우로 한칸씩만 움직일 수 있음
자신보다 작은 물고기는 먹을 수 없음
-자신의 크기 수 만큼 물고기를 먹으면 크기 1 증가  
총 몇간을 움직이면 다 먹을수 있는가

: BFS 문제임
각가의 노드에서 연결된 노드로 탐색하는 방식으로 진행이 가능
상어가 움직이는 위치에서 다음 움직이는 위치를 탐색가능
각각의 노드는 `상, 하, 좌, 우` 와 연결되어있음.

n : N^2 (field size)
시간 복잡도 : $O(n^2)$
공간 복잡도 : $O(3N)$ : distance_hashing + fieldMap + visited

1. `상 하 좌 우` 를 탐색, 갈수 있는 곳 과 갈수 없는곳, 먹을수 있는곳 을 구분
	1. 중복 탐색을 막기위해, 기록
	2. 갈수 있는곳, 먹을수 있는곳 리스트를 반환
2. 먹을수 있는곳이 반환된 리스트에 있다면
	1. 상어 이동후, 정보 갱신
	2. 1번으로 돌아가서 다시
3. 먹을수 있는 곳이 없는경우
	1. 갈수 있는곳 모든 좌표에 대해 1번을 수행
			단,  같은 depth에 대해 동시에 수행
4. 갈수 있는곳이 없는경우
		탐색을 종료