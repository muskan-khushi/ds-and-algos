# Last index of One

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given a string  **s** consisting only of '0' and '1', find the last index at which '1' occurs. If '1' is not present in the string, return -1.

 **Examples:** 

```
Input: s = "01001"
Output: 4
Explanation: Last index of  1 in given string is 4.

```

```
Input: s = "0"
Output: -1
Explanation: Since, 1 is not present, so output is -1.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-19T13:45:25.364Z  

```cpp
class Solution {
  public:
    int lastIndex(string &s) {
        // code here
        int n = s.size();
        for (int i=n-1; i>=0; i--){
            if (s[i] == '1') return i;
        }
        return -1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/last-index-of-15847/1)