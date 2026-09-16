class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ans = new int[nums.length-k+1];
        int ansIndex = 0;

        Deque<Integer> dq = new ArrayDeque<>();

        for (int right = 0; right <nums.length; right++){

            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[right]){
                dq.pollLast();
            }
            dq.offerLast(right);
            int left = right - k + 1;

            if (!dq.isEmpty() && dq.peekFirst() < left){
                dq.pollFirst();
            }

            if (right >= k-1){
                ans[ansIndex] = nums[dq.peekFirst()];
                ansIndex++;
            }

        }
        return ans;
        
    }
}