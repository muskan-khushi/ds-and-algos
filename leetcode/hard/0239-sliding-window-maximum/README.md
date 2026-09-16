# Sliding Window Maximum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return  *the max sliding window*.

 

 **Example 1:** 

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

 **Example 2:** 

```
Input: nums = [1], k = 1
Output: [1]

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- 1 <= k <= nums.length

## Solution

**Language:** Java  
**Runtime:** 29 ms (beats 84.61%)  
**Memory:** 143.1 MB (beats 94.84%)  
**Submitted:** 2026-09-16T05:25:38.873Z  

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ans = new int[nums.length-k+1];
        int ansIndex = 0;

        Deque<Integer> dq = new ArrayDeque<>();

        for (int right = 0; right <nums.length; right++){

            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[right]){
                dq.pollLast();
            }
            dq.offerLast(right);
            int left = right - k + 1;

            if (!dq.isEmpty() && dq.peekFirst() < left){
                dq.pollFirst();
            }

            if (right >= k-1){
                ans[ansIndex] = nums[dq.peekFirst()];
                ansIndex++;
            }

        }
        return ans;
        
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/sliding-window-maximum/)