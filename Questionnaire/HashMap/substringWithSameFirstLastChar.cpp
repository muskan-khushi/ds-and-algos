// https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

// Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

// Examples:

// Input: s = "abcab"
// Output: 7
// Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
// Input: s = "aba"
// Output: 4
// Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"
// Constraints:
// 1 <= |s| <= 104
// s contains lower case english alphabets

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstring(string &s) {
        // Create a map to store frequency of each character in string s
        // Key: character (e.g., 'a', 'b', 'c')
        // Value: number of times this character appears in s
        unordered_map<char, int> freq;

        // Iterate over each character in the string s
        for (char c : s) {
            // Increase the count for this character by 1
            freq[c]++;
        }

        int count = 0;  // This will hold the total count of valid substrings

        // Now iterate over each entry (key-value pair) in the frequency map
        for (auto &entry : freq) {
            // entry.first  -> the character (like 'a', 'b', etc.)
            // entry.second -> the frequency count of that character in s

            int f = entry.second;  // Store frequency of this character in f for easier use

            // Explanation of formula:
            // For a character that appears f times,
            // Number of substrings that start and end with this character = f * (f + 1) / 2
            // This counts:
            // - all single-character substrings (each occurrence counts as 1)
            // - all substrings formed by choosing start and end indices among these f occurrences
            //
            // For example, if 'a' appears 3 times, substrings starting and ending with 'a' are:
            // single chars: 3
            // pairs: (3 choose 2) = 3
            // total = 3 + 3 = 6 = 3 * (3 + 1) / 2

            count += (f * (f + 1)) / 2;  // Add contribution for this character to total count
        }

        // Return the total count of substrings starting and ending with the same character
        return count;
    }
};
