def list_to_deximal(num) -> int:
    i = 10
    ret = num[0]
    for value in num[1:]:
        ret += value * i
        i *= 10
    return ret


def is_prime(prime_board, num) -> bool:
    num = list_to_deximal(num)
    if num == 1:
        return False
    if num <= 3:
        return True
    if num in prime_board:
        return prime_board[num]
    i = 1
    while (i := i + 1) * i <= num:
        if num % i == 0:
            prime_board[num] = False
            return False
    prime_board[i] = True
    return True


def solution(n, k):
    nums, cur = [], []
    while n != 0:
        reft = n % k
        n //= k
        if reft != 0:
            cur.append(reft)
            continue
        if len(cur) != 0:
            nums.append(cur)
        cur = []
    nums.append(cur)
    answer = 0
    prime_board = {}
    for item in nums:
        if is_prime(prime_board, item):
            answer += 1
    return answer


print(solution(110011, 10), 2)
print(solution(437674, 3), 3)
