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