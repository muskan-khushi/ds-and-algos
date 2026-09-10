# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** Java  
**Runtime:** 0 ms  
**Memory:** 42.8 MB  
**Submitted:** 2026-09-10T03:45:12.587Z  

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int left = 0;
        int maxLen = 0;

        for  (int right = 0; right < s.length(); right++){
            while (set.contains(s.charAt(left))){
                set.remove(s.charAt(left));
                left++;
            }
            set.add(s.charAt(right));
            maxLen = Math.max(maxLen, right-left+1);
        }

        return maxLen;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)