/*
 * LeetCode Problem: Two Sum
 * 
 * Problem Statement:
 * Given an array of integers nums and an integer target, return the indices of the two numbers
 * that add up to the target. You may assume that each input has exactly one solution, and you
 * cannot use the same element twice. You can return the answer in any order.
 * 
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * Explanation: nums[0] + nums[1] = 2 + 7 = 9
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ============ APPROACH 1: BRUTE FORCE (NESTED LOOP) ============
/*
 * Time Complexity: O(n²) - We check every pair of elements
 * Space Complexity: O(1) - No extra space used
 * 
 * How it works:
 * - Use two nested loops to check every pair of numbers
 * - For each number at index i, check all numbers after it (index j)
 * - If nums[i] + nums[j] equals target, return the indices
 * - Simple but inefficient for large arrays
 */
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    
    // Outer loop: iterate through each element
    for (int i = 0; i < n; i++) {
        // Inner loop: check all elements after current element
        for (int j = i + 1; j < n; j++) {
            // If sum equals target, we found our answer
            if (nums[i] + nums[j] == target) {
                return {i, j};  // Return indices as a vector
            }
        }
    }
    
    // If no solution found, return empty vector
    return {};
}

// ============ APPROACH 2: HASH MAP (OPTIMAL) ============
/*
 * Time Complexity: O(n) - Single pass through array
 * Space Complexity: O(n) - Hash map stores up to n elements
 * 
 * How it works:
 * - Use a hash map to store values we've seen and their indices
 * - For each number, calculate what complement we need: complement = target - current_num
 * - Check if complement already exists in hash map
 * - If yes, we found our pair; if no, add current number to map and continue
 * - Much faster because hash map lookup is O(1)
 */
vector<int> twoSumHashMap(vector<int>& nums, int target) {
    // Hash map to store: key = number, value = its index
    unordered_map<int, int> seen;
    
    // Single pass through array
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int complement = target - current;  // What number do we need?
        
        // Check if complement was already seen
        if (seen.find(complement) != seen.end()) {
            // Found it! Return indices of complement and current number
            return {seen[complement], i};
        }
        
        // Store current number and its index for future lookups
        seen[current] = i;
    }
    
    // No solution found
    return {};
}

// Main function to test both approaches
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    cout << "Array: [2, 7, 11, 15], Target: 9\n";
    
    vector<int> result1 = twoSumBruteForce(nums, target);
    cout << "Brute Force Result: [" << result1[0] << ", " << result1[1] << "]\n";
    
    vector<int> result2 = twoSumHashMap(nums, target);
    cout << "Hash Map Result: [" << result2[0] << ", " << result2[1] << "]\n";
    
    return 0;
}