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
**Runtime:** 14 ms (beats 50.26%)  
**Memory:** 46.3 MB (beats 80.47%)  
**Submitted:** 2026-09-17T04:11:48.502Z  

```java
class Solution {
    public int maxVowels(String s, int k) {
        int left = 0;
        int vowelCount = 0;
        int maxCount = 0;

        for (int right = 0; right < s.length(); right++){
            if (isVowel(s.charAt(right))) vowelCount++;
            if (right - left + 1 == k){
                maxCount = Math.max(maxCount, vowelCount);
                if (isVowel(s.charAt(left))) vowelCount--;
                left++;
            }
        }

        return maxCount;
    }

    private boolean isVowel(char c){
        return c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u';
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)