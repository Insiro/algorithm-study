from collections import defaultdict


class Problem:
    def __init__(self, n_coins, coins) -> None:
        self.coins = coins
        self.last_idx = n_coins - 1


def initalize():
    from sys import stdin

    input = stdin.readline

    n, target = [int(i) for i in input().split(" ")]
    coins = []
    for _ in range(n):
        coins.append(int(input()))
    dp = defaultdict(lambda: defaultdict(lambda: None))
    return target, Problem(n, coins), dp


def get_combinations(left, coin_idx, problem, dp):
    if left == 0:
        return 1

    cur_coin = problem.coins[coin_idx]
    result = 0

    if problem.last_idx == coin_idx:
        if left % cur_coin == 0:
            result = 1
        dp[coin_idx][left] = result
        return result
    used = 0
    while used <= left:
        if (ret:=dp[coin_idx][left]) is None:  # if not memorized
            ret = get_combinations(left - used, coin_idx + 1, problem, dp)
        result += ret
        used += cur_coin
    dp[coin_idx][left] = result
    return result


target, problem, dp = initalize()
result = get_combinations(target, 0, problem, dp)
print(result, end="")


def test(target: int, coins: list[int], answer: int):
    dp = defaultdict(lambda: defaultdict(lambda: None))
    problem = Problem(len(coins), coins)
    ret = get_combinations(target, 0, problem, dp)
    assert ret == answer


test(2, [1, 2], 2)
test(3, [1, 2], 2)
test(4, [1, 2], 3)
