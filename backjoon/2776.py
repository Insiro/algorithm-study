"""
title: 암기왕
id : 2776
platform : 백준
date : 23-03-28
url : https://www.acmicpc.net/problem/2776
state: pass
"""

from sys import stdin

N_cases = int(stdin.readline())
for case in range(1, N_cases + 1):
    stdin.readline()
    book1_str = stdin.readline()
    book1 = {}
    for i in book1_str.split(" "):
        book1[int(i)] = True

    stdin.readline()
    book2_str = stdin.readline()
    book2 = book2_str.split(" ")
    for i in book2[:-1]:
        ret = 1 if int(i) in book1 else 0
        print(ret)
    ret = 1 if int(book2[-1]) in book1 else 0
    print(ret, end="") if case == N_cases else print(ret)
