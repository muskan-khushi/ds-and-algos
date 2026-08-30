# Perfect Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A  **perfect number**  is a  **positive integer**  that is equal to the sum of its  **positive divisors**, excluding the number itself. A  **divisor**  of an integer `x` is an integer that can divide `x` evenly.

Given an integer `n`, return `true` *if* `n` *is a perfect number, otherwise return* `false`.

 

 **Example 1:** 

```
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

```

 **Example 2:** 

```
Input: num = 7
Output: false

```

 

 **Constraints:** 

- 1 <= num <= 108

## Solution

**Language:** Python  
**Runtime:** 7 ms (beats 41.61%)  
**Memory:** 19.4 MB (beats 16.94%)  
**Submitted:** 2026-08-30T04:15:34.192Z  

```py
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1:
            return False

        ans = 1
        i = 2

        while i*i <= num:
            if num%i == 0:
                ans += i

                if i != num//i:
                    ans += num//i
             
            i+=1

        return num == ans
```

---

[View on LeetCode](https://leetcode.com/problems/perfect-number/)