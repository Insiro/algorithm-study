from collections import defaultdict

MAX = 500000


class Board:
    def __init__(self, N, road, K):
        self.N = N
        self.road = defaultdict(lambda: defaultdict(lambda: MAX))
        self.K = K
        for src, dest, cost in road:
            if not (K < cost):
                self.update_cost(src, dest, cost)

    def update_sub(self, src, dest, cost):
        for dest2 in list(self.road[dest].keys()):
            cost2 = self.road[dest][dest2] + cost
            if not (self.K < cost2):
                self.update_cost(dest2, src, cost2)

    def update_cost(self, src, dest, cost):
        if src == dest:
            return
        if self.road[src][dest] > cost:
            self.road[src][dest] = cost
            self.road[dest][src] = cost
            self.update_sub(src, dest, cost)
            self.update_sub(dest, src, cost)


def solution(N, road, K):
    # N개의 마을 , K이하로 배달 가능한 시간
    # 음식점 1, 배달받을수 있는 음식점은?
    board = Board(N, road, K)
    return len(board.road[1].keys()) + 1


assert solution(5, [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]], 3) == 4
assert solution(6, [[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]], 4) ==4
print("pass_all")