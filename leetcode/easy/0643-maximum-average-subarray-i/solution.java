class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;

        int sum = 0;
        for (int left = 0; left < k; left++){
            sum += nums[left];
        }

        int maxSum = sum;

        for (int i=k; i<n; i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxSum = Math.max(maxSum, sum);
        }

        return (double)maxSum/k;
    }
}