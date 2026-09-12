class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0;
        int right = 0;
        for (int weight : weights){
            left = Math.max(weight, left);
            right += weight;
        }

        while (left < right){
            int mid = left + (right - left)/2;

            int daysUsed = 1;
            int currentWeight = 0;

            for (int weight : weights){
                if (currentWeight + weight > mid){
                    daysUsed++;
                    currentWeight = 0;
                }
                currentWeight += weight;
            }

            if (daysUsed <= days) right = mid;
            else left =mid+1;
        }
        return left;
    }
}