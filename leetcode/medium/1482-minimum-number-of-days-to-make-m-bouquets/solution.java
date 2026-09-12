class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if ((long)m*k > n) return -1;

        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;

        for (int bloom : bloomDay){
            left = Math.min(left, bloom);
            right = Math.max(right, bloom);
        }

        while (left < right){
            int mid = left + (right - left)/2;

            int consecutive = 0;
            int bouquets = 0;

            for (int day : bloomDay){
                if (day <= mid){
                    consecutive++;
                    if (consecutive == k){
                        bouquets++;
                        consecutive = 0;
                    }
                }
                else consecutive = 0;
            }

            if (bouquets >= m) right = mid;
            else left = mid+1;
        }

        return left;
    }
}