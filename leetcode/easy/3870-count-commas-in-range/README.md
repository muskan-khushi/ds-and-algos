# Count Commas in Range

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer `n`.

Return the  **total**  number of commas used when writing all integers from `[1, n]` (inclusive) in  **standard**  number formatting.

In  **standard**  formatting:

- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

 

 **Example 1:** 

 **Input:**  n = 1002

 **Output:**  3

 **Explanation:** 

The numbers `"1,000"`, `"1,001"`, and `"1,002"` each contain one comma, giving a total of 3.

 **Example 2:** 

 **Input:**  n = 998

 **Output:**  0

 **Explanation:** 

All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

 **Constraints:** 

- 1 <= n <= 105

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 15.77%)  
**Memory:** 8.6 MB (beats 51.38%)  
**Submitted:** 2026-09-08T10:04:24.037Z  

```cpp
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        long long ans = 0;

        long long start = 1000;
        int commas = 1;

        while (start <= n){
            long long end = min((long long)n, start*1000-1);
            ans += (end - start + 1)*commas;

            start *= 1000;
            commas++;
        }

        return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-commas-in-range/)