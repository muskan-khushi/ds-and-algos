# Longest Repeating Character Replacement

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return  *the length of the longest substring containing the same letter you can get after performing the above operations*.

 

 **Example 1:** 

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

```

 **Example 2:** 

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of only uppercase English letters.
- 0 <= k <= s.length

## Solution

**Language:** Java  
**Runtime:** 7 ms (beats 89.24%)  
**Memory:** 45.6 MB (beats 98.45%)  
**Submitted:** 2026-09-17T03:26:32.995Z  

```java
class Solution {
    public int characterReplacement(String s, int k) {
        //Algorithm
        //Dynamic Sliding Window Pattern
        // kisi bhi window mei jis bhi element ka maxFreq hogaa, window length - maxFreq <= k hona chhaiye

        //store frequency of each element in a particular window
        int[] freq = new int[26];

        //max freq of any element in a window
        int maxFreq = 0;

        //ans storing the max length
        int ans = 0;
        int left = 0;

        //sliding window pattern
        for (int right = 0; right<s.length(); right++){
            int index = s.charAt(right) - 'A';
            freq[index]++;
            maxFreq = Math.max(maxFreq, freq[index]);

           //invalid window, shrink from left
            while ((right-left+1) - maxFreq > k){
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            //valid window
            ans = Math.max(ans, right-left+1);
        }
        return ans;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)