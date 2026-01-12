/*
LeetCode 75: Sort Colors

Given an array `nums` with n objects colored red, white, or blue,
represented as integers 0, 1, and 2 respectively, sort them in-place
so that objects of the same color are adjacent, with the colors in
the order red, white, and blue.

You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 2:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Constraints:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2

Follow up: Can you come up with a one-pass algorithm using only O(1) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // low  → boundary for 0s (everything before low is 0)
        // mid  → current index we are examining
        // high → boundary for 2s (everything after high is 2)

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        // Loop until all unknown elements are processed
        // Unknown region is from mid to high
        while (mid <= high) {

            // CASE 1: current element is 0
            if (nums[mid] == 0) {

                // A 0 must go to the front (0-region)
                // nums[low] is either 1 or already processed
                // So we swap current 0 with nums[low]
                swap(nums[low], nums[mid]);

                // We have now placed a correct 0 at index low
                // So we expand the 0-region
                low++;

                // The current position is also resolved
                // So we move mid forward
                mid++;
            }

            // CASE 2: current element is 1
            else if (nums[mid] == 1) {

                // 1 belongs in the middle
                // No swapping needed
                // Just move forward
                mid++;
            }

            // CASE 3: current element is 2
            else { // nums[mid] == 2

                // A 2 must go to the end (2-region)
                // nums[high] is currently unknown
                // So we swap current 2 with nums[high]
                swap(nums[mid], nums[high]);

                // We have now placed a correct 2 at index high
                // So we shrink the unknown region from the right
                high--;

                // IMPORTANT:
                // We do NOT move mid here
                // Because the element swapped from nums[high]
                // has not been checked yet
            }
        }
    }
};
