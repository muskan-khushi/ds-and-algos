/**
 * LeetCode Question 643: Maximum Average Subarray I
 * 
 * Given an integer array nums consisting of n elements, and an integer k.
 * Find a contiguous subarray whose length is equal to k that has the maximum average value 
 * and return this maximum average.
 * 
 * Any answer with a difference of 10^-5 from the actual answer will be accepted.
 * 
 * Example 1:
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 + (-5) + (-6) + 50) / 4 = 51 / 4 = 12.75
 * 
 * Example 2:
 * Input: nums = [5], k = 1
 * Output: 5.00000
 * 
 * Constraints:
 * - n == nums.length
 * - 1 <= k <= n <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * 
 * Approach: Use a sliding window of size k to calculate sums, tracking the maximum sum.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        // -----------------------------------------
        // STEP 1: Build the FIRST window of size k
        // -----------------------------------------
        // We calculate the sum of the first k elements.
        // This represents the first subarray.
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // This is the maximum sum seen so far
        int maxSum = windowSum;

        // -----------------------------------------
        // STEP 2: Slide the window across the array
        // -----------------------------------------
        // We move the window one step at a time.
        // Each move:
        //  - adds one new element (right side)
        //  - removes one old element (left side)
        int l = 0;

        for (int r = k; r < n; r++) {

            // ADD the new element entering the window
            windowSum += nums[r];

            // REMOVE the element leaving the window
            windowSum -= nums[l];

            // Move the left pointer forward
            l++;

            // Update the maximum sum seen so far
            maxSum = max(maxSum, windowSum);
        }

        // -----------------------------------------
        // STEP 3: Return the maximum average
        // -----------------------------------------
        // Average = sum / k
        return (double) maxSum / k;
    }
};
