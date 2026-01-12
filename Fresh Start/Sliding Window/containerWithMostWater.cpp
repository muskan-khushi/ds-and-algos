/*
LeetCode Problem 11: Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that 
the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum area of water a container can store.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The vertical lines are at index 1 and 8. 
Container formed has width = 8 - 1 = 7 and height = min(8, 7) = 7.
Area = 7 * 7 = 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
- n == height.length
- 2 <= n <= 10^5
- 0 <= height[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        // left  → pointer at the beginning of the array
        // right → pointer at the end of the array
        // These two pointers form the container walls
        int left = 0;
        int right = height.size() - 1;

        // This will store the maximum water area found so far
        int maxArea = 0;

        // We keep checking containers until the two pointers meet
        while (left < right) {

            // The height of water is limited by the shorter wall
            // Because water will spill from the shorter side
            int h = min(height[left], height[right]);

            // Width is the distance between the two walls
            int w = right - left;

            // Area of the current container
            int area = h * w;

            // Update the maximum area if this container is better
            maxArea = max(maxArea, area);

            // IMPORTANT GREEDY STEP:
            // We move the pointer that has the smaller height
            // Reason:
            // - Width will always decrease when pointers move
            // - The only way to possibly increase area is to find a taller wall
            if (height[left] < height[right]) {
                // Left wall is smaller, so try to find a taller one
                left++;
            } else {
                // Right wall is smaller or equal, so try to find a taller one
                right--;
            }
        }

        // After checking all possible containers, return the best one
        return maxArea;
    }
};
