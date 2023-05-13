---
title: 빵집
id: 3109
platform: 백준
url: https://www.acmicpc.net/problem/3109
date: 2023-04-15
time: None
state: pass
---

# 문제

유명한 제빵사 김원웅은 빵집을 운영하고 있다. 원웅이의 빵집은 글로벌 재정 위기를 피해가지 못했고, 결국 심각한 재정 위기에 빠졌다.
원웅이는 지출을 줄이고자 지출을 살펴보던 중에, 가스비가 제일 크다는 것을 알게되었다. 따라서 원웅이는 근처 빵집의 가스관에 몰래 파이프를 설치해 훔쳐서 사용하기로 했다.
빵집이 있는 곳은 R\*C 격자로 표현할 수 있다. 첫째 열은 근처 빵집의 가스관이고, 마지막 열은 원웅이의 빵집이다.
원웅이는 가스관과 빵집을 연결하는 파이프를 설치하려고 한다. 빵집과 가스관 사이에는 건물이 있을 수도 있다. 건물이 있는 경우에는 파이프를 놓을 수 없다.
가스관과 빵집을 연결하는 모든 파이프라인은 첫째 열에서 시작해야 하고, 마지막 열에서 끝나야 한다. 각 칸은 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 연결할 수 있고, 각 칸의 중심끼리 연결하는 것이다.
원웅이는 가스를 되도록 많이 훔치려고 한다. 따라서, 가스관과 빵집을 연결하는 파이프라인을 여러 개 설치할 것이다. 이 경로는 겹칠 수 없고, 서로 접할 수도 없다. 즉, 각 칸을 지나는 파이프는 하나이어야 한다.
원웅이 빵집의 모습이 주어졌을 때, 원웅이가 설치할 수 있는 가스관과 빵집을 연결하는 파이프라인의 최대 개수를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 R과 C가 주어진다. (1 ≤ R ≤ 10,000, 5 ≤ C ≤ 500)

다음 R개 줄에는 빵집 근처의 모습이 주어진다. '.'는 빈 칸이고, 'x'는 건물이다. 처음과 마지막 열은 항상 비어있다.

# 코드

```python
class Field:
	def __init__(self, rows: int, colums: int, field: list[list[bool]]) -> None:
		self.rows = rows
		self.colums = colums
		self.field = field
	def link(self, y: int, x: int) -> bool:
		stack = [(y, x)]
		while stack:
			y, x = stack.pop()
			if y in (-1, self.rows) or not self.field[y][x]:
				continue
			self.field[y][x] = False  # here is visited
			if x == self.colums - 1:  # linked
				return True
			new_x = x + 1
			for i in [1, 0, -1]:
				stack.append((y + i, new_x))
		return False
def initalize():
	from sys import stdin
	input = stdin.readline
	rows, colums = [int(item) for item in input().split(" ")]
	field_map: list[list[bool]] = []
	for _ in range(rows):
		line_input = input()
		line = [line_input[i] == "." for i in range(colums)]
		field_map.append(line)
	return Field(rows, colums, field_map)

def solution(field: Field) -> int:
	answer = 0
	for i in range(0, field.rows):
		if field.link(i, 0):
			answer += 1
	return answer

case = initalize()
print(solution(case), end="")
```

#### testcase

```python
def test(case, value, print_result=False):
	field = Field(len(case), len(case[0]), case)
	ret = solution(field)
	if print_result:
		print(ret)
	return ret == value
# region case1
case1 = [
	[True, False, False, True, True],
	[True, True, False, True, True],
	[True, True, True, True, True],
	[True, True, True, False, True],
    [True, True, True, False, True]]
assert test(case1, 2)
# endregion
# region case2
case2 = [
	[True, True, False, True, True, True, True, True, True, True],
	[True, True, True, True, True, False, True, True, True, True],
	[True, False, True, True, True, True, False, True, True, True],
	[True, True, True, False, True, True, True, False, False, True],
	[True, True, True, True, True, True, True, True, True, True],
	[True, True, True, True, False, True, True, True, True, True]]
assert test(case2, 5)
# endregion
# region case3
case3 = [
	[True, True, True],
	[True, True, True],
	[True, True, True]]
assert test(case3, 3)
# endregion
# region case4
case4 = [
	[False, False, False],
	[False, False, False],
	[False, False, False]]
assert test(case4, 0)
# endregion
# region case5
case5 = [
	[True, False, True],
	[True, False, True],
	[True, False, True]]
assert test(case5, 0)
# endregion
# region case6
case6 = [
	[False, False, False],
	[True, False, False],
	[False, True, False],
    [False, False, True]]
assert test(case6, 1)
# endregion
# region case7
case7 = [
	[True, True, True, True, True],
	[True, True, True, True, True],
	[True, True, True, True, True],
	[True, True, True, False, True],
	[True, True, True, False, True],
	[True, True, True, True, True],
	[True, True, True, False, True],
	[True, True, True, False, True],
	[True, True, True, False, True],
	[True, True, True, True, True]]
assert test(case7, 5)
# endregion
```

# 풀이
시간복잡도 : `O(Column * Row*3 )` 
재귀로 풀었을떄는 시간초과 발생

`dfs` + `dp`
갈수없거나 방문한지역은 False로 표시해 재탐색을 방지
마지막 노드가 True인경우,  연결갯수 갱신

1. 현재 노드를 방문불가로 마킹
2. 현재 노드가 마지막 맨끝이면 True 반환
3. 왼쪽 3개 탐색 (위, 중간, 가운데)
	1. 갈 수 없다면 sibling 노드
	2. 갈 수 있다면 children 노드 탐색 (1번으로)
True갯수 반환