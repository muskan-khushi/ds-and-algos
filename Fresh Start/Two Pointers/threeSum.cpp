/*
 * LeetCode Problem 3Sum (Problem #15)
 * 
 * PROBLEM STATEMENT:
 * Given an integer array nums of length n, return all unique triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Input: nums = [-1, 0, 1, 2, -1, -4]
 * Output: [[-1, -1, 2], [-1, 0, 1]]
 * 
 * APPROACH: Sorting + Two Pointers
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) excluding output array
 */

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    // Edge case: if array has less than 3 elements, no triplet possible
    if (n < 3) return result;
    
    // Step 1: Sort the array - this helps in avoiding duplicates and using two-pointer approach
    sort(nums.begin(), nums.end());
    
    // Step 2: Iterate through each element as the first number of triplet
    for (int i = 0; i < n - 2; i++) {
        // Optimization: if current number is positive, no triplet can sum to 0
        if (nums[i] > 0) break;
        
        // Avoid duplicate triplets by skipping duplicate values at position i
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Step 3: Use two pointers to find remaining two numbers
        int left = i + 1;      // Start from next element
        int right = n - 1;     // Start from end
        int target = -nums[i]; // We need two numbers that sum to -nums[i]
        
        // Two pointer approach to find pairs that sum to target
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                // Found a valid triplet
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicate values at left pointer
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicate values at right pointer
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                // Move pointers to continue searching for more triplets
                left++;
                right--;
            } 
            else if (sum < target) {
                // Sum is too small, move left pointer right to increase sum
                left++;
            } 
            else {
                // Sum is too large, move right pointer left to decrease sum
                right--;
            }
        }
    }
    
    return result;
}