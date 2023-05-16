---
title : AC 
id : 5430
platform : Programmers
url : https://www.acmicpc.net/problem/5430
date : 2023-04-16
time : None
state : pass
---
# 문제
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 **R**(뒤집기)과 **D**(버리기)가 있다.
함수 R은 배열에 있는 수의 순서를 뒤집는 함수
D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

#### 입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.
# 코드
```python
from collections import deque
def calc(commands, numbers) -> str:
    reverse = False
    for cmd in commands:
        if cmd == "R":
            reverse = not reverse
            continue
        if len(numbers) == 0:  # cannot pop (enpty list)
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
```


#### testcase
```python
assert calc("RDD", [1, 2, 3, 4]) == "[2,1]"
assert calc("RR", []) == "[]"
assert calc("DD", [42]) == "error"
assert calc("RRD", [1, 1, 2, 3, 5, 8]) == "[1,2,3,5,8]"
assert calc("D", []) == "error"
```


# 풀이

deque 자료형을 이용해 양쪽에서 값을 꺼낸뒤
출력때만 순서를 뒤집음