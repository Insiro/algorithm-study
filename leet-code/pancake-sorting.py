from typing import List


class Solution:
    def flip(self, point: int):
        for i in range(int(point / 2) + 1):
            self.arr[i], self.arr[point - i] = self.arr[point - i], self.arr[i]

    def pancakeSort(self, arr: List[int]) -> List[int]:
        self.length = len(arr)
        self.arr = arr
        ret = []
        for i in range(self.length - 1, -1, -1):
            # region find max
            idx = i
            value = self.arr[i]
            for j, cur in enumerate(self.arr[:i]):
                if cur > value:
                    idx = j
                    value = cur
            # endregion
            if idx == i:
                continue
            ret.append(idx + 1)
            ret.append(i + 1)
            self.flip(idx)
            self.flip(i)
        return ret


solution = Solution()
# case1
arr = [3, 2, 4, 1]
solution.pancakeSort(arr)
assert solution.arr == sorted(arr)
# case 2
arr = [1, 2, 3]
solution.pancakeSort(arr)
assert solution.arr == sorted(arr)
