"""
3109 빵집
https://www.acmicpc.net/problem/3109
"""
from sys import stdin

input = stdin.readline


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
            self.field[y][x] = False  # here is visited
            if x == self.colums - 1:  # linked
                return True
            new_x = x + 1
            for i in [1, 0, -1]:
                stack.append((y + i, new_x))
        return False


def initalize():
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
    [True, True, True, False, True],
]
assert test(case1, 2)
# endregion
# region case2
case2 = [
    [True, True, False, True, True, True, True, True, True, True],
    [True, True, True, True, True, False, True, True, True, True],
    [True, False, True, True, True, True, False, True, True, True],
    [True, True, True, False, True, True, True, False, False, True],
    [True, True, True, True, True, True, True, True, True, True],
    [True, True, True, True, False, True, True, True, True, True],
]
DEBUG = True
assert test(case2, 5)
# endregion
# region case3
case3 = [
    [True, True, True],
    [True, True, True],
    [True, True, True],
]
assert test(case3, 3)
# endregion
# region case4
case4 = [
    [False, False, False],
    [False, False, False],
    [False, False, False],
]
assert test(case4, 0)
# endregion
# region case5
case5 = [
    [True, False, True],
    [True, False, True],
    [True, False, True],
]
assert test(case5, 0)
# endregion
# region case6
case6 = [
    [False, False, False],
    [True, False, False],
    [False, True, False],
    [False, False, True],
]
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
    [True, True, True, True, True],
]
assert test(case7, 5)
# endregion
