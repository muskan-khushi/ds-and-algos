/**
 * LeetCode Question 167: Two Sum II - Input Array Is Sorted
 *
 * Problem:
 * Given an array of integers `numbers` that is already sorted in non-decreasing order,
 * find two numbers such that they add up to a specific target number.
 *
 * Return the indices of the two numbers (1-indexed) as an integer array `answer` of size 2,
 * where 1 <= answer[0] < answer[1] <= numbers.length.
 *
 * Note:
 * - You may assume that each input has exactly one solution.
 * - You cannot use the same element twice.
 * - Your solution must use only constant O(1) extra space.
 *
 * Approach:
 * Use two pointers technique:
 * - Initialize left pointer at the beginning and right pointer at the end.
 * - If sum of elements at left and right equals target, return their indices.
 * - If sum is less than target, move left pointer right (increase sum).
 * - If sum is greater than target, move right pointer left (decrease sum).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * @param numbers Vector of sorted integers
 * @param target The target sum
 * @return Vector of two 1-indexed positions
 */

 #include <bits/stdc++.h>
 using namespace std;

 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while (l < r){
            if (nums[l] + nums[r] == target) return {l+1, r+1};
            else if (nums[l] + nums[r] < target) l++;
            else r--;
        }
        return {};
    }
};