# Perfect Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a number  **n,**  check if the number is  **perfect**  or not. A number is said to be perfect if  **sum**  of all its factors excluding the number itself is equal to the  **number**.

 **Examples:** 

```
Input: n = 6
Output: true 
Explanation: Factors of 6 are 1, 2, 3 and 6. Excluding 6 their sum is 6 which is equal to n itself. So, it's a Perfect Number.
```

```
Input: n = 10
Output: false
Explanation: Factors of 10 are 1, 2, 5 and 10. Excluding 10 their sum is 8 which is not equal to n itself. So, it's not a Perfect Number.

```

```
Input: n = 15
Output: false
Explanation: Factors of 15 are 1, 3, 5, 15. Excluding 15 their sum is 9 which is not equal to n itself. So, it's not a Perfect Number.
```

 **Constraints:** 
1 ≤ n ≤ 109

## Solution

**Language:** Python  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T04:18:10.844Z  

```py
class Solution:
    def isPerfect(self, n):
        # code here 
        ans = 1
        i = 2
        
        while i*i <= n:
            if n%i == 0:
                ans += i
                
                if i != n//i:
                    ans += n//i
                    
            i+=1
        
        return n==ans
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1)