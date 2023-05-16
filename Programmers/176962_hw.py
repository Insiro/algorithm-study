"""
과제 진행하기
https://school.programmers.co.kr/learn/courses/30/lessons/176962
"""


# plans : [[name, start {hh:mm}, time (분단위)]]
class HomeWork:
    def __init__(self, plan):
        self.name = plan[0]
        self.duration = int(plan[2])
        times = plan[1].split(":")
        self.start = int(times[0]) * 60 + int(times[1])

    def __lt__(self, other):
        return self.start < other.start


def solution(plans):
    answer = []
    hws = [HomeWork(plan) for plan in plans]  # O(n)
    hws.sort()  # o(nlogn)

    cur_time = 0
    hw_stack = []
    stack_len = 0
    for item in hws:
        while stack_len != 0:
            doing = hw_stack[-1]
            end_time = cur_time + doing.duration
            if end_time < item.start:  # when previous hw is end and next is not started
                hw_stack.pop()
                cur_time = end_time
                stack_len -= 1
                answer.append(doing.name)
                continue
            if end_time == item.start:  # when previous hw is end and next is started
                hw_stack.pop()
                stack_len -= 1
                answer.append(doing.name)
            elif end_time > item.start:
                doing.duration = end_time - item.start
            break
        cur_time = item.start
        hw_stack.append(item)
        stack_len += 1
        continue

    for item in reversed(hw_stack):
        answer.append(item.name)

    return answer


assert ["korean", "english", "math"] == solution(
    [
        ["korean", "11:40", "30"],
        ["english", "12:10", "20"],
        ["math", "12:30", "40"],
    ]
)
assert ["science", "history", "computer", "music"] == solution(
    [
        ["science", "12:40", "50"],
        ["music", "12:20", "40"],
        ["history", "14:00", "30"],
        ["computer", "12:30", "100"],
    ]
)
assert ["bbb", "ccc", "aaa"] == solution(
    [
        ["aaa", "12:00", "20"],
        ["bbb", "12:10", "30"],
        ["ccc", "12:40", "10"],
    ]
)
