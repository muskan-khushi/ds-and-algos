class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int left = 1;
        int right = 0;
        for (int pile : piles){
            right = Math.max(right, pile);
        }

        while (left < right){
            int mid = left + (right-left)/2;
            int hours = 0;
            
            for (int pile : piles) hours += (mid+pile-1)/mid;

            if (hours <= h) right = mid;
            else left = mid+1;
        }
        return left;
    }
}