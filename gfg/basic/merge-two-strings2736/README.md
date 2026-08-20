# Alternate Merge Two Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given two strings  **s1**  and  **s2**, merge them alternatively i.e. the first character of s1 then the first character of s2 and so on till the strings end.

 **Note:**  Add the whole string if other string is empty.

 **Examples:** 

```
Input: s1 = "Hello", s2 = "Bye"
Output: HBeylelo
Explanation: The characters of both the given strings are arranged alternatlively.

```

```
Input: s1 = "abc", s2 = "def"
Output: adbecf
Explanation: The characters of both the given strings are arranged alternatlively.

```

 **Constraints:** 
1<=|s1|, |s2| <=103

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-20T03:26:33.439Z  

```cpp
class Solution {
  public:
    string merge(string &s1, string &s2) {
        // code here
        int i=0, j=0;
        string ans = "";
        
        while (i < s1.size() || j < s2.size()){
            if (i < s1.size()){
                ans += s1[i];
                i++;
            }
            
            if (j < s2.size()){
                ans += s2[j];
                j++;
            }
        }
        
        return ans;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/merge-two-strings2736/1)