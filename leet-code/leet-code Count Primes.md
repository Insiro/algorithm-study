---
title : CountPrimes
id : 204
platform : leetcode
url : https://leetcode.com/problems/count-primes
date : 2023-04-28
time : None
state : pass
---
# 문제


#### 입력

# 코드
```python
class Solution:
    def countPrimes(self, n: int) -> int:
        if n in [0,1]:
            return 0
        primeMatrix = [True]*(n-1)
        primeMatrix[0] = False
        last = n-1
        for i in range(1,last):
            if primeMatrix[i]  == False:
                continue
            j = i
            while (j:=j+i+1) < last:
                primeMatrix[j] = False
        return sum(primeMatrix)
```

