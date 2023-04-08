---
title : 햄버거최대 몇개드실수있나요?
id : 27923
platform : 백준
url : https://www.acmicpc.net/problem/27923
date : 2023-04-08
time : None
state : pass
---
# 문제
지훈이는 자신이 햄버거를 한 번에 얼마나 먹을 수 있는지, ‘햄최몇’을 측정하기로 했다. 한 번에 햄버거 4$4$개를 먹을 수 있다면 ’햄최4$4$’, 30$30$개를 먹을 수 있다면 ’햄최30$30$’이라 부른다. 보통 햄최몇을 측정할 때는 한 종류의 햄버거만 먹지만, 지훈이는 한 가지만 계속 먹으면 질리기 때문에 다양한 햄버거를 먹으면서 햄최몇을 측정하기로 했다.

지훈이가 준비한 햄버거는 총 $N$개이고, 먹었을 때 각 햄버거의 질량만큼 위 속 질량이 늘어난다. 준비한 햄버거를 원하는 순서로 먹을 수 있지만, 햄버거를 먹는 동안 항상 위 속 질량이 지훈이의 위의 용량보다 크지 않아야 한다.

또, 햄버거만 계속 먹으면 물리기 때문에 지훈이는 $K$개의 콜라를 마시려고 한다. 각 콜라는 지훈이가 미리 정해 놓은 시점에, 햄버거를 먹기 직전에 마신다. 콜라를 마시면 그 후 햄버거 $L$개를 먹을 동안 ‘콜라 효과’를 얻을 수 있고, 콜라 효과는 중첩될 수 있다. 콜라 효과가 지속되는 동안 지훈이가 햄버거를 먹으면, 먹음과 동시에 그 햄버거의 질량에 비례해 위 속 질량이 소화되어 사라진다! 구체적으로, **질량이 $m$인 햄버거를 콜라 효과가 $C$번 중첩되었을 때 먹었다면  $\lfloor \frac{m}{2^C} \rfloor$만큼만 위 속 질량이 증가한다.** 이때, 실수 $x$에 대하여 $\lfloor x\rfloor$는 $x$보다 크지 않은 가장 큰 정수를 의미한다.

지훈이는 자신이 생각한 햄최몇보다 많은 햄버거를 준비했지만, 음식을 남기면 아깝기 때문에 햄버거를 다 먹고 싶어졌다! 햄버거를 먹는 순서를 적절히 설정하여 지훈이가 준비한 햄버거를 다 먹기 위해 필요한 위의 용량의 최솟값을 계산하자. 지훈이는 충분히 굶은 상태이기 때문에, 현재 위 속 질량은 0$0$이다.

### 입력
첫 번째 줄에 준비한 햄버거의 개수 $N$, 콜라의 개수 $K$, 콜라 효과의 지속 시간 $L$이 공백으로 구분되어 주어진다. (1≤$N,K,L$≤200 000)$(1\leq N, K, L\leq 200\ 000)$ 

두 번째 줄에 각 햄버거의 질량을 나타내는 $N$개의 정수 $m_1,m_2,...,m_n$이 공백으로 구분되어 주어진다. $(1\leq m_i\leq 10^9)$ 

세 번째 줄에 콜라를 마시는 시기를 나타내는 $K$개의 정수 $t_1,t_2,...,t_K$이 공백으로 구분되어 주어진다. $i$번째 콜라는 $t_i$번째로 햄버거를 먹기 직전에 마신다. $(1\leq t_i\leq N)$

# 코드
```python
class Problem:
    def __init__(
        self,
        n_burger: int,
        p_coke: int,
        burgers: list[int],
        cokes: list[int],
    ):
        self.n_burger = n_burger
        self.burgers = burgers  # 버거 질량 list
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
```


#### testcase
```python
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
```




# 풀이
누적합, Greedy
1. 콜라 효과가 큰곳에 햄버거 질량이 높은곳에 배정 (Greedy)
2. 콜라 효과를 계산 (누적합)
	먼저 콜라 효과의 지속시간이 없다고 가정하고. 풀이를 한다.
	-> 단순히 누적합으로, 최대 콜라 효과를 구할수가 있음
	콜라 효과의 지속시간에 한계가 있음
	-> 지속시간 이후의 값들에 현재의 누적합을 더해주면 되는 느낌

