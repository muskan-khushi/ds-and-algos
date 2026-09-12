class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
    
        int left = 0;
        int right = 0;
        for (int weight : weights){
            left = Math.max(weight, left);
            right += weight;
        }

        while (left < right){
            int mid = left + (right-left)/2;

            int currentWeight = 0;
            int daysUsed = 1;

            for (int weight : weights){
                if (currentWeight + weight > mid){
                    currentWeight = 0;
                    daysUsed++;
                }
                currentWeight += weight;
            }

            if (daysUsed <= days) right = mid;
            else left = mid+1;

        }

        return left;
        
    }
}