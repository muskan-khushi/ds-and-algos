class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //Algorithm
        //binary search on smaller array for position of cut1
        // median

        int n = nums1.length;
        int m = nums2.length;

        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);

        int totalLeft = (m+n+1)/2;

        int low = 0;
        int high = n;

        while (low <= high){
            int cut1 = low + (high-low)/2;
            int cut2 = totalLeft - cut1;

            int nums1Left, nums1Right, nums2Left, nums2Right;

            if (cut1 == 0) nums1Left = Integer.MIN_VALUE;
            else nums1Left = nums1[cut1-1];

            if (cut1 == n) nums1Right = Integer.MAX_VALUE;
            else nums1Right = nums1[cut1];

            if (cut2 == 0) nums2Left = Integer.MIN_VALUE;
            else nums2Left = nums2[cut2-1];

            if (cut2 == m) nums2Right = Integer.MAX_VALUE;
            else nums2Right = nums2[cut2];

            if (nums1Left <= nums2Right && nums2Left <= nums1Right){
                if ((m+n) % 2 != 0) return Math.max(nums1Left, nums2Left);
                else {
                    int leftMax = Math.max(nums1Left, nums2Left);
                    int rightMin = Math.min(nums2Right, nums1Right);

                    return (leftMax + rightMin)/2.0;
                }
            }

            else if (nums1Left > nums2Right) high = cut1-1;
            else low = cut1+1;
        }

        return 0.0;
    }
}