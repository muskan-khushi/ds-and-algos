# Strong Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

A Strong Number is a number whose value is equal to the sum of the factorials of its digits.

Given a positive integer  **n**, determine whether it is a Strong Number. Return  **true**  if it is a Strong Number; otherwise, return  **false**.

 **Examples:** 

```
Input: 145
Output: true
Explanation: The sum of the factorials of its digits is: 1! + 4! + 5! = 1 + 24 + 120 = 145.
Since the sum equals the original number, 145 is a Strong Number.

```

```
Input: 5314
Output: false
Explanation: The sum of the factorials of its digits is not equal to 5314. Therefore, it is not a Strong Number.
```

 **Constraints:** 
1 ≤ n ≤ 104

## Solution

**Language:** Python  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T04:31:37.839Z  

```py
class Solution:
    def isStrong(self, n):
        # code here
        s = str(n)
        ans = 0
        
        for ch in s:
            digit = int(ch)
            fact = 1
            for i in range(1,digit+1):
                fact*=i
            ans += fact
            
        return ans == n
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/strong-numbers4336/1)