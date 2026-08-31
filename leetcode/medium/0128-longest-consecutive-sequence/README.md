# Longest Consecutive Sequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an unsorted array of integers `nums`, return  *the length of the longest consecutive elements sequence.* 

You must write an algorithm that runs in `O(n)` time.

 

 **Example 1:** 

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

```

 **Example 2:** 

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

```

 **Example 3:** 

```
Input: nums = [1,0,1,2]
Output: 3

```

 

 **Constraints:** 

- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 85 ms (beats 36.57%)  
**Memory:** 88.8 MB (beats 67.35%)  
**Submitted:** 2026-08-31T12:06:22.938Z  

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        for (int num : nums){
            numSet.insert(num);
        }

        int longest = 0;

        for (int num : numSet){
            if (numSet.count(num-1)) continue;
            int length = 1;
            int current = num;
            while (numSet.count(current+1)){
                current++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/)