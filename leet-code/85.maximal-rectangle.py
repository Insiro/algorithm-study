#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#


# @lc code=start
class Solution:
    def __init__(self) -> None:
        self.matrix: list[list[str]] = []
        self.heights: list[list[int]] = []

    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        self.matrix = matrix
        rows = len(matrix)
        columns = len(matrix[0])
        self.heights = []
        for _ in range(rows):
            line = [0] * columns
            self.heights.append(line)
        for row in range(rows):
            for column in range(columns):
                if matrix[row][column] == "0":
                    continue
                if row == 0:
                    self.heights[row][column] = 1
                else:
                    self.heights[row][column] = self.heights[row - 1][column] + 1
        max_size = 0
        for row in range(rows - 1, -1, -1):
            for column in range(columns - 1, -1, -1):
                if (ret := self.get_size(row, column)) > max_size:
                    max_size = ret
        print(self.heights)
        return max_size

    def get_size(self, y, x):
        min_height = self.heights[y][x]
        max_size, width = 0, 1
        while x != -1:
            if self.matrix[y][x] == 0:
                break
            if (h := self.heights[y][x]) < min_height:
                min_height = h
            if (size := width * min_height) > max_size:
                max_size = size
            width += 1
            x -= 1
        return max_size


# @lc code=end
