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

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T04:24:03.285Z  

```cpp
class Solution {
  public:
  public:
    bool isStrong(int n) {
        // code here.
        int ans = 0;
        string s = to_string(n);
        for (char ch : s){
            int digit = (ch - '0');
            int fact = 1;
            for (int i=1; i<=digit; i++){
                fact *= i;
            }
            ans += fact;
        }
        
        return ans == n;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/strong-numbers4336/1)