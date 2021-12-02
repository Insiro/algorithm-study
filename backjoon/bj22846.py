"""
# 22846 인증된 쉬운 게임    21.12.01 success

둘은 자신의 차례에 모니터에 쓰여있는 수의 약수를 하나 선택해 모니터에 있는 값에 더한다. 이때 제한 K를 초과한 사람이 패배하게 된다. 
캐릭터 팀에서 만들어진 캐릭터는 게임을 할 때 최선의 전략으로 플레이를 하게 된다. K가 주어졌을 때 누가 이기게 되는지 구해보자!


# 입력
입력의 첫 줄에 자연수 K가 주어진다. 
# 출력
칼리가 이기게 된다면 Kali를 링고가 이기게 된다면 Ringo를 출력한다. 

# 예제
|input|output|
|--|--|
|2|Kali|
|3|Ringo|
"""

from typing import List, Any, Dict, Tuple


def get_divigers(target: int, max_num: int) -> List[int]:
    divigers: List[int] = []
    i = 1
    while i <= max_num and i * i <= target:
        if target % i == 0:
            divigers.append(i)
            if (target/i <= max_num) and (not i * i == target):
                divigers.append(int(target/i))
        i = i+1
    divigers.sort()
    divigers.reverse()
    return divigers


class SimpleGame:
    players: List[str] = ["Kali", "Ringo"]

    def __init__(self, num: int):
        self.__target: int = num
        # Dict : {leftValue : useNum}, useNum 0 means NotWinnable
        self.__dp_cache: Dict[int, int] = {}

    def predict_winner(self) -> Any:
        v = self.__predict_dp(1)
        return self.players[v == 0]

    def __predict_dp(self, cur_num) -> int:
        if cur_num in self.__dp_cache:
            return self.__dp_cache[cur_num]

        diff = self.__target - cur_num
        if self.__is_base_condition(diff):
            self.__dp_cache[cur_num] = diff
            return diff

        divigers = get_divigers(cur_num, diff)
        result = self.__is_winnable(cur_num, divigers)
        self.__dp_cache[cur_num] = result
        return result

    def __is_base_condition(self, value):
        return value == 1 or value == 0

    def __is_winnable(self, base_number, divigers: List[int]):
        result = 0
        for diviger in divigers:
            ret = self.__predict_dp(base_number + diviger)
            if ret == 0:
                result = diviger
                break
        return result


def solve():
    game = SimpleGame(int(input()))
    ret = game.predict_winner()
    print(ret)


if __name__ == "__main__":
    solve()
