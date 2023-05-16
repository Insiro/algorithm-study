from collections import deque


def calc(commands, numbers) -> str:
    reverse = False
    for cmd in commands:
        if cmd == "R":
            reverse = not reverse
            continue
        if len(numbers) == 0:  # cannot pop (enpty list)
            return "error"
        if reverse:
            deque.pop(numbers)
        else:
            deque.popleft(numbers)
    if reverse:
        numbers.reverse()
    out = ",".join([str(item) for item in numbers])
    return f"[{out}]"


def initalize():
    commands = input()
    n_numbers = int(input())
    in_numbers = input()
    numbers = deque()
    if n_numbers == 0:
        return commands, []
    for num in in_numbers[1:-1].split(","):
        numbers.append(int(num))
    return commands, numbers


def solve():
    n_case = int(input())
    for i in range(n_case):
        command, numbers = initalize()
        ret = calc(command, numbers)
        if i == n_case - 1:
            print(ret, "")
        else:
            print(ret)


solve()

# case1
assert calc("RDD", [1, 2, 3, 4]) == "[2,1]"
assert calc("RR", []) == "[]"
assert calc("DD", [42]) == "error"
assert calc("RRD", [1, 1, 2, 3, 5, 8]) == "[1,2,3,5,8]"
assert calc("D", []) == "error"
