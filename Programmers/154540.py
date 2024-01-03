import sys

sys.setrecursionlimit(10000)


class Board:
    def __init__(self, maps) -> None:
        self.maps = maps
        self.raws = len(maps)
        self.columns = len(maps[0])


bounding = [[1, 0], [-1, 0], [0, 1], [0, -1]]


def dfs(board: Board, y, x):
    scale = int(board.maps[y][x])
    board.maps[y] = board.maps[y][:x] + "X" + board.maps[y][x + 1 :]
    for p in bounding:
        new_y = y + p[0]
        new_x = x + p[1]
        if new_y < 0 or new_y == board.raws or new_x < 0 or new_x == board.columns:
            continue
        if board.maps[new_y][new_x] == "X":
            continue
        scale += dfs(board, new_y, new_x)

    return int(scale)


def solution(maps):
    if len(maps) == 0 or len(maps[0][0]) == 0:
        return [-1]
    answer = []
    board = Board(maps)
    for y in range(board.raws):
        for x in range(board.columns):
            if board.maps[y][x] == "X":
                continue
            answer.append(dfs(board, y, x))
    if not answer:
        return [-1]
    answer.sort()
    return answer
