# Maximum Number of Vowels in a Substring of Given Length

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s` and an integer `k`, return  *the maximum number of vowel letters in any substring of* `s` *with length* `k`.

 **Vowel letters**  in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

 

 **Example 1:** 

```
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

```

 **Example 2:** 

```
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

```

 **Example 3:** 

```
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- 1 <= k <= s.length

## Solution

**Language:** Java  
**Runtime:** 20 ms (beats 27.98%)  
**Memory:** 45.2 MB (beats 99.86%)  
**Submitted:** 2026-09-17T03:53:25.431Z  

```java
class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int left = 0;
        int vowelCount = 0;
        int maxCount = 0;
        for (int right = 0; right<n; right++){
            if (s.charAt(right) == 'a' || s.charAt(right) == 'e' || s.charAt(right) == 'i' || s.charAt(right) == 'o' || s.charAt(right) == 'u') vowelCount++;

            if (right-left+1 == k){
                maxCount = Math.max(vowelCount, maxCount);
                if (s.charAt(left) == 'a' ||
                    s.charAt(left) == 'e' ||
                    s.charAt(left) == 'i' ||
                    s.charAt(left) == 'o' ||
                    s.charAt(left) == 'u') {

                    vowelCount--;
                }
                left++;
            }
        }
        return maxCount;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)