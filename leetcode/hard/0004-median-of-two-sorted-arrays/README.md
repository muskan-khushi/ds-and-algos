# Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

 **Example 1:** 

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

```

 **Example 2:** 

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

 

 **Constraints:** 

- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106

## Solution

**Language:** Java  
**Runtime:** 1 ms (beats 100.00%)  
**Memory:** 48.8 MB (beats 71.06%)  
**Submitted:** 2026-09-13T04:15:18.080Z  

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.length;
        int n = nums2.length;

        int totalLeft = (m+n+1)/2;

        int low = 0;
        int high = m;

        while (low <= high){
            int cut1 = low + (high - low)/2;

            int cut2 = totalLeft - cut1;

            int nums1Left, nums1Right, nums2Left, nums2Right;

            if (cut1 == 0) nums1Left = Integer.MIN_VALUE;
            else nums1Left = nums1[cut1-1];

            if (cut1 == m) nums1Right = Integer.MAX_VALUE;
            else nums1Right = nums1[cut1];

             if (cut2 == 0) {
                nums2Left = Integer.MIN_VALUE;
            } else {
                nums2Left = nums2[cut2 - 1];
            }


            if (cut2 == n) {
                nums2Right = Integer.MAX_VALUE;
            } else {
                nums2Right = nums2[cut2];
            }

            if (nums1Left <= nums2Right && nums2Left <= nums1Right){
                if ((m+n) % 2 == 1) return Math.max(nums1Left, nums2Left);
                else {
                    int leftMax = Math.max(nums1Left, nums2Left);
                    int rightMin = Math.min(nums1Right, nums2Right);

                    return (leftMax + rightMin)/2.0;
                }
            }

            if (nums1Left > nums2Right) high = cut1 - 1;
            else low = cut1+1;
        }
        return 0.0;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)