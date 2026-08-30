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

**Language:** C++  
**Runtime:** 2080 ms (beats 28.13%)  
**Memory:** 7.9 MB (beats 21.30%)  
**Submitted:** 2026-08-30T04:08:53.910Z  

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int ans = 0;
        for (int i=1; i<num; i++){
            if (num % i == 0) ans += i;
        }
        return ans == num;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/perfect-number/)