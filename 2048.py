"""https://www.acmicpc.net/problem/12100"""
class Board:
    def __init__(self, size, field) -> None:
        self.size= size
        self.field= field
    def __merge(self,x1, y1, x2,y2 ):
        ret = self.field[y1][x1] + self.field[y2][x2]
        self.field[y1][x1] =0
        self.field[y2][x2] = 0
        return ret
    def __up_line(self, x):
        base = 0
        idx = 0
        cmp = 1
        while (idx+cmp) < self.size:
            block1 = self.field[idx][x]
            if block1 ==0:
                idx +=1
                continue
            adder = idx+cmp
            block2 = self.field[adder][x]
            if block2 == 0:
                cmp+=1
                continue

            if block1 == block2:
                self.field[base][x] =self.__merge(base, x,base+cmp, x)
                base +=1
                idx +=cmp+1
                cmp = 1
                continue
            else:
                self.field[base][x] = block1
                self.field[idx][x] = 0
                self.field[base+1][x] = block2
                self.field[adder][x] = 0
                base +=1
                cmp = 0
                idx +=1
            

    def up(self):
        for i in range(self.size):
            self.__up_line(i)


    def down(self):

    def left(self):



def initalize():
    from sys import stdin
    input = stdin.readline
    size = int(input())

    field = []
    for _ in range(size):
        field.append([int(i)for i in input().split(" ")])
    return Board(size, field)