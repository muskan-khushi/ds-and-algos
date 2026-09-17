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