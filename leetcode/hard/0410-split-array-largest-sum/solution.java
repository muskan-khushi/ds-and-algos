class Solution {
    public int splitArray(int[] nums, int k) {
        int low = 0;
        int high = 0;

        for (int num : nums){
            low = Math.max(low, num);
            high += num;
        }

        while (low < high){
            int mid = low + (high-low)/2;

            if (canSplit(nums, k, mid)){
                high = mid;
            }
            else low = mid+1;
        }
        return low;
    }

    private boolean canSplit(int[] nums, int k, int limit){
        int subarrays = 1;
        int currSum = 0;

        for (int num : nums){
            if (currSum + num > limit){
                currSum = num;
                subarrays++;
            }
            else currSum += num;
        }

        return subarrays <= k;

    }
}