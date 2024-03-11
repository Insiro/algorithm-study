from unittest import TestCase


def gcd(m: int, n: int) -> int:
    while n:
        t = m % n
        m, n = n, t
    return abs(m)


def solution(w: int, h: int) -> int:
    g = gcd(w, h)
    wg = int(w / g)
    hg = int(h / g)
    blocks = wg + hg - 1
    return w * h - blocks * g


class Test(TestCase):
    def test1(self):
        w, h = 8, 12
        self.assertEqual(80, solution(w, h))
