class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        //max sum of subarray of unique elements
        HashSet<Integer> set = new HashSet<>();
        int sum = 0;
        int maxSum = 0;
        int left = 0;

        for (int right = 0; right<nums.length; right++){
            while (set.contains(nums[right])){
                set.remove(nums[left]);
                sum -= nums[left];
                left++;
            }
            set.add(nums[right]);
            sum += nums[right];

            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}