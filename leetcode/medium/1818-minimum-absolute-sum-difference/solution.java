class Solution {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] sorted = nums1.clone();
        Arrays.sort(sorted);

        long total = 0;
        int maxGain = 0;

        for (int i=0; i<n; i++){
            int oldDiff = Math.abs(nums1[i] - nums2[i]);
            total += oldDiff;

            int index = lowerBound(sorted, nums2[i]);
            if (index < n){
                int newDiff = Math.abs(sorted[index] - nums2[i]);
                int gain = oldDiff - newDiff;
                maxGain = Math.max(gain, maxGain);
            }
            if (index > 0){
                int newDiff = Math.abs(sorted[index-1]-nums2[i]);
                int gain = oldDiff - newDiff;
                maxGain = Math.max(gain, maxGain);
            }
        }
        return (int)((total-maxGain)%1_000_000_007);
    }

    private int lowerBound(int[] arr, int target){
        int left = 0;
        int right = arr.length;

        while (left < right){
            int mid = left + (right-left)/2;
            if (arr[mid] >= target) right = mid;
            else left = mid+1;
        }
        return left;
    }
}