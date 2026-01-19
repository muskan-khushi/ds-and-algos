/**
 * LeetCode Question 3: Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 *   Input: s = "abcabcbb"
 *   Output: 3
 *   Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 *   Input: s = "bbbbb"
 *   Output: 1
 *   Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 *   Input: s = "pwwkew"
 *   Output: 3
 *   Explanation: The answer is "wke", with the length of 3.
 * 
 * Constraints:
 *   - 0 <= s.length <= 5 * 10^4
 *   - s consists of English letters, digits, symbols and spaces.
 * 
 * @param s The input string
 * @return The length of the longest substring without repeating characters
 */

 #include <bits/stdc++.h>
 using namespace std;

 // FILE: longest_unique_substring.cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        // -----------------------------------------
        // STEP 1: Track characters inside window
        // -----------------------------------------
        // Set stores unique characters in the current window
        unordered_set<char> seen;

        // -----------------------------------------
        // STEP 2: Sliding window pointers
        // -----------------------------------------
        int l = 0;
        int maxLen = 0;

        // -----------------------------------------
        // STEP 3: Expand window using r
        // -----------------------------------------
        for (int r = 0; r < n; r++) {

            // -----------------------------------------
            // STEP 4: Shrink window if duplicate found
            // -----------------------------------------
            // If s[r] already exists, remove from left
            while (seen.count(s[r])) {

                seen.erase(s[l]);
                l++;
            }

            // -----------------------------------------
            // STEP 5: Add new character
            // -----------------------------------------
            seen.insert(s[r]);

            // -----------------------------------------
            // STEP 6: Update answer
            // -----------------------------------------
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
