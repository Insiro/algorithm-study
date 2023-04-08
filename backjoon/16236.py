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
        arr = [[], []]  # VISITABLE, EATABLE
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


def test_cases():
    # region case1
    board = Board(3, [[0, 0, 0], [0, 0, 0], [0, 9, 0]])
    Shark(2, 1).move(board)
    assert board.time == 0
    # endregion
    # region case2
    board = Board(3, [[0, 0, 1], [0, 0, 0], [0, 9, 0]])
    Shark(2, 1).move(board)
    assert board.time == 3
    # endregion
    # region case3
    board = Board(4, [[4, 3, 2, 1], [0, 0, 0, 0], [0, 0, 9, 0], [1, 2, 3, 4]])
    Shark(2, 2).move(board)
    assert board.time == 14
    # endregion
    # region usercase 1
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
    # endregion
    # region case4
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
    # endregion
    # region case 5
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
    # endregion
    # region case 6
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


test_cases()
boards, shark = initalize()
shark.move(boards)
print(boards.time, end="")
