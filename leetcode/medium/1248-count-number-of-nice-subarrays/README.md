# Count Number of Nice Subarrays

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `nums` and an integer `k`. A continuous subarray is called  **nice**  if there are `k` odd numbers on it.

Return  *the number of  **nice**  sub-arrays*.

 

 **Example 1:** 

```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

```

 **Example 2:** 

```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

```

 **Example 3:** 

```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

```

 

 **Constraints:** 

- 1 <= nums.length <= 50000
- 1 <= nums[i] <= 10^5
- 1 <= k <= nums.length

## Solution

**Language:** Java  
**Runtime:** 14 ms (beats 51.59%)  
**Memory:** 59.6 MB (beats 38.75%)  
**Submitted:** 2026-09-17T03:37:25.187Z  

```java
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        //ans = number of subarrays having atmost k odd numbers - 
        //number of subarrays having at most k-1 odd numbers

        return atMost(nums, k) - atMost(nums, k-1);
    }

    private int atMost(int[] nums, int k){
        int left = 0;
        int oddCount = 0;
        int ans = 0; //number of subarrays having k odd numbers

        for (int right = 0; right < nums.length; right++){
            if (nums[right]%2 != 0) oddCount++;

            while (oddCount > k){
                if (nums[left] % 2 != 0) oddCount--;
                left++;
            }

            ans += right-left+1;
        }

        return ans;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/count-number-of-nice-subarrays/)