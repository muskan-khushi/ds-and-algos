class Solution {
    public int longestOnes(int[] nums, int k) {
        //in any window - right-left+1 - freq[1] <= k

        int n = nums.length;
        int[] freq = new int[2];
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++){
            freq[nums[right]]++;

            while ((right - left + 1) - freq[1] > k){
                if (nums[left] == 1) freq[1]--;
                left++;
            }

            maxLen = Math.max(right-left+1, maxLen);

        }
        return maxLen;
    }
}