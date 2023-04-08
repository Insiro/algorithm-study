"""
햄최몇?
https://www.acmicpc.net/problem/27923
"""


class Problem:
    def __init__(
        self,
        n_burger: int,
        p_coke: int,
        burgers: list[int],
        cokes: list[int],
    ):
        self.n_burger = n_burger
        self.burgers = burgers  # 버거 질량 list
        self.burgers.sort()

        # 콜라 한번에 마신 횟수 계산
        coke_powers = [0] * n_burger
        cummerated = [0] * n_burger
        for item in cokes:
            coke_powers[item - 1] += 1
        # 콜라 효과 중첩, 누적합
        cummerated[0] = coke_powers[0]
        for i in range(n_burger):
            cummerated[i] = cummerated[i - 1] + coke_powers[i]
        # 콜라 효과 중첩 끝나는 시점 갱신
        for i in range(n_burger - 1, p_coke - 1, -1):
            cummerated[i] -= cummerated[i - p_coke]
        # 정렬된 콜라 중첩수
        self.coke_power_sorted = sorted(cummerated)


def solution(problem: Problem):
    size = 0
    burgers = problem.burgers
    coke_len = len(problem.coke_power_sorted)
    for idx in range(problem.n_burger - 1, -1, -1):
        if coke_len == 0:
            size += burgers[idx]
            continue
        power = problem.coke_power_sorted[coke_len - 1]
        size += burgers[idx] >> power
        coke_len -= 1
    return size


def initalize():
    from sys import stdin

    input = stdin.readline
    line = input().split(" ")
    burgers = [int(item) for item in input().split(" ")]
    cokes = [int(item) for item in input().split(" ")]
    return Problem(int(line[0]), int(line[2]), burgers, cokes)


case = initalize()
print(solution(case), end="")

# case 1
case = Problem(5, 1, [1, 2, 3, 4, 5], [1])
assert solution(case) == 12
# case2
case = Problem(
    1,
    1,
    [1000000000],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    + [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    + [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
)
assert solution(case) == 0
