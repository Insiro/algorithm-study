from collections import defaultdict
from enum import Enum
from unittest import TestCase
from typing import Self

POSSIBLE = 1
IMPOSSIBLE = 0
"""
# desc
check the status of board is possible status when playing "tictactoe" normally
board size is 3*3
make one line in same Signature is Winning

# return
return value is 0 or 1
if is possible case: return 1
else 0
"""


class Direction(Enum):
    HORIZONTAL = 0
    VERTICAL = 1
    DIAGONAL = 2  # line 0 is left top to right bottom


SYM = ["O", "X"]


class Line:
    direction: Direction
    line: int

    def __init__(self, direction: Direction, line: int) -> None:
        self.line = line
        self.direction = direction

    def isPointShareWith(self, other: Self) -> bool:
        if self.direction != other.direction:
            return True
        return self.direction == Direction.DIAGONAL


class Counter:
    def __init__(self) -> None:
        self.lines: list[list[Line]] = [[], []]
        self.symbols = defaultdict(int)
        self.nDirs = defaultdict(int)

    def add_item(self, symbol: str):
        self.symbols[symbol] += 1

    def add_line(self, line: int, direction: Direction, symbol: str) -> int:
        self.nDirs[direction] += 1
        if self.nDirs[direction] > 1:
            return IMPOSSIBLE
        self.lines[symbol == "O"].append(Line(direction, line))
        return POSSIBLE

    def valid(self) -> int:
        # O가 선공이므로, O가 X보다 1개 많거나, 갯수가 같아야 함.
        ndiff = self.symbols["O"] - self.symbols["X"]
        if ndiff not in [1, 0]:
            return IMPOSSIBLE
        n1, n2 = len(self.lines[1]), len(self.lines[0])
        if n1 == 0 and n2 == 0:  # 둘 다 완성을 못함
            return POSSIBLE
        if n1 != 0 and n2 != 0:  # 둘 다 완성한 경우
            return IMPOSSIBLE
        if n1 != 0 and ndiff == 0:  # 선공이 완성했지만, 후공도 둔경우
            return IMPOSSIBLE
        if n2 != 0 and ndiff == 1:  # 후공이 완성했지만, 선공이 또 둔경우
            return IMPOSSIBLE
        return POSSIBLE


def solution(board: list[str]) -> int:
    counter = Counter()
    # counting [o, x] and check line count of horizontal
    for y, line in enumerate(board):
        for x, item in enumerate(line):
            counter.add_item(item)
        # check horizontal line
        if line[0] in SYM and line[0] == line[1] and line[1] == line[2]:
            if IMPOSSIBLE == counter.add_line(y, Direction.HORIZONTAL, line[0]):
                return IMPOSSIBLE
    # counting line of vertical
    for x in range(0, 3):
        symbol = board[0][x]
        if symbol in SYM and symbol == board[1][x] and symbol == board[2][x]:
            if IMPOSSIBLE == counter.add_line(x, Direction.VERTICAL, symbol):
                return IMPOSSIBLE

    # counting diagonal line
    if (symbol := board[1][1]) in SYM:
        if symbol == board[0][0] and symbol == board[2][2]:
            counter.add_line(0, Direction.DIAGONAL, symbol)
        if symbol == board[0][2] and symbol == board[2][0]:
            counter.add_line(1, Direction.DIAGONAL, symbol)
    return counter.valid()


class TestSolution(TestCase):
    def test1(self):
        print("In method", self._testMethodName)
        case = ["O.X", ".O.", "..X"]
        self.assertEqual(1, solution(case))

    def test2(self):
        print("In method", self._testMethodName)
        case = ["OOO", "...", "XXX"]
        self.assertEqual(0, solution(case))

    def test3(self):
        print("In method", self._testMethodName)
        case = ["...", ".X.", "..."]
        self.assertEqual(0, solution(case))

    def test4(self):
        print("In method", self._testMethodName)
        case = ["...", "...", "..."]
        self.assertEqual(1, solution(case))

    def test5(self):
        print("In method", self._testMethodName)
        case = ["O.X", "XO.", "X.O"]
        self.assertEqual(0, solution(case))

    def test6(self):
        print("In method", self._testMethodName)
        case = ["O.X", "XO.", "..O"]
        self.assertEqual(1, solution(case))

    def test7(self):
        print("In method", self._testMethodName)
        case = ["O..", "O.X", "O.X"]
        self.assertEqual(1, solution(case))

    def test8(self):
        print("In method", self._testMethodName)
        case = ["OO.", "XXX", "OO."]
        self.assertEqual(1, solution(case))
