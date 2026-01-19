// LeetCode 904: Fruit Into Baskets
// 
// You are visiting a farm that has tree arranged in a row with fruits of two types: apples and oranges.
// You want to collect as much fruit as possible.
// 
// However, you have two baskets, and each basket can only hold a single type of fruit. 
// There is no limit on the amount of fruit each basket can hold.
// 
// You will start at any position in the row, then move to the right one by one.
// You are in charge of choosing fruit for each basket.
// 
// The important rules are:
// - At each position, you must pick a fruit of type A or type B. You pick fruit from this position into one of the baskets.
// - Starting from the leftmost position to the rightmost, you must pick fruit one by one.
// - If the basket for type A is full, you have to reset the whole type A basket before the next fruit.
// - You cannot start over the trees you have visited.
// - For each fruit position, you have exactly one basket to pick the fruit into.
//
// Given an integer array fruits where fruits[i] is the type of fruit the ith tree has, 
// return the maximum number of fruits you can collect using the two baskets.
//
// Example:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can collect [1,2,1].
//
// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can collect [1,2,2] using 2 baskets.

#include <bits/stdc++.h>
using namespace std;

// FILE: fruit_into_baskets.cpp

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        // -----------------------------------------
        // STEP 1: Data structure to track fruit counts
        // -----------------------------------------
        // We need to know how many types of fruits are in the window.
        unordered_map<int, int> count;

        // -----------------------------------------
        // STEP 2: Sliding window pointers
        // -----------------------------------------
        int l = 0;          // left boundary of window
        int maxLen = 0;     // best window size found

        // -----------------------------------------
        // STEP 3: Expand window using r
        // -----------------------------------------
        for (int r = 0; r < n; r++) {

            // Add the current fruit to the window
            count[fruits[r]]++;

            // -----------------------------------------
            // STEP 4: Shrink window if invalid
            // -----------------------------------------
            // Window is invalid if we have more than 2 fruit types
            while (count.size() > 2) {

                // Remove one fruit from the left
                count[fruits[l]]--;

                // If count becomes zero, remove that fruit type
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }

                // Move left pointer
                l++;
            }

            // -----------------------------------------
            // STEP 5: Update answer
            // -----------------------------------------
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
