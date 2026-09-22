# Permutation in String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

 

 **Example 1:** 

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

```

 **Example 2:** 

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

```

 

 **Constraints:** 

- 1 <= s1.length, s2.length <= 104
- s1 and s2 consist of lowercase English letters.

## Solution

**Language:** Java  
**Runtime:** 5 ms (beats 97.39%)  
**Memory:** 44 MB (beats 60.93%)  
**Submitted:** 2026-09-22T13:19:34.642Z  

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        //find a substring in s2 that has the same length as s1 and contains the exact same characters as s1
        //verify the substring has the same character frequencies as s1
        //sliding window approach - examine each substring of s2 with length equal to s1
        
        //to efficiently track whether current window matches s1
        //counter that starts with the character counts in s1
        //decrement counts for character entering our window
        //and increment count for leaving

        //need -> how many distinct characters still need to be matched
        //when need = 0 done

        int distinctCharsNeeded = 0;
        int[] charFrequency = new int[26];

        for (char ch : s1.toCharArray()){
            int index = ch - 'a';
            charFrequency[index]++;
            if (charFrequency[index] == 1) distinctCharsNeeded++;  
        }

        int patternLength = s1.length();
        int textLength = s2.length();

        int left = 0;
        for (int right = 0; right < textLength; right++){
            int index = s2.charAt(right) - 'a';
            charFrequency[index]--;

            if (charFrequency[index] == 0) distinctCharsNeeded--;

            if (right - left + 1 > patternLength){
                int leftIndex = s2.charAt(left) - 'a';
                if (charFrequency[leftIndex] == 0) distinctCharsNeeded++;
                charFrequency[leftIndex]++;
                left++;
            }

            if (distinctCharsNeeded == 0) return true;
        }
        return false;

    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/permutation-in-string/)