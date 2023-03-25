from case_checker import Checker
from sys import stdin, maxsize


def solution(arr):
    positive_arr = get_positive_arr(arr)
    negative_arr = get_negative_arr(arr)
    answer = 0

    for idx in range(len(positive_arr) - 1):
        positive = positive_arr[idx]
        negative = negative_arr[idx]
        if negative[0] >= positive[0] and negative[1] <= positive[1]:
            answer += 1
    return -1 if answer == 0 else answer


def get_positive_arr(records):
    max_happy = records[-1][0]
    min_tiered = records[-1][1]
    records = reversed(records)
    if min_tiered == 0:
        min_tiered = maxsize
    positive_arr = [[max_happy, min_tiered]]
    records.__next__()
    for happy, tiered in records:
        if happy > max_happy:
            max_happy = happy
        if tiered < min_tiered:
            min_tiered = tiered
        positive_arr.append([max_happy, min_tiered])
    return list(reversed(positive_arr))


def get_negative_arr(records):
    max_tiered = records[0][1]
    min_happy = records[0][0]
    if min_happy == 0:
        min_happy = maxsize
    negative_arr = [[min_happy, max_tiered]]
    for happy, tiered in records[1:]:
        if happy < min_happy:
            min_happy = happy
        if tiered > max_tiered:
            max_tiered = tiered
        negative_arr.append([min_happy, max_tiered])
    return negative_arr


def read_input():
    N = int(stdin.readline())
    records = []

    for _ in range(N):
        input_days = [int(a) for a in stdin.readline().split(" ")]
        records.append(input_days)
    return records


checker = Checker(solution)
checker([[5, 1], [4, 2], [3, 3], [2, 5], [1, 4]], 3)
checker([[1, 1], [2, 2], [3, 3]], -1)
checker([[0, 0], [0, 0], [0, 0]], 2)


records = read_input()
print(solution(records), end="")
