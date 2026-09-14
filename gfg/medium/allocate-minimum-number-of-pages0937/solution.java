class Solution {
    public int findPages(int[] arr, int k) {
        // code here
        // arr[i] - no of pages in the ith book
        // k - number of students
        
        if (arr.length < k) return -1;
        
        long low = 0;
        long high = 0;
        
        for (int num : arr){
            low = Math.max(num, low);
            high += num;
        }
        
        while (low < high){
            long mid = low + (high-low)/2;
            
            if (canBeSplit(arr, k, mid)) high = mid;
            else low = mid+1;
        }
        return (int)low;
    }
    
    private boolean canBeSplit(int[] arr, int k, long limit){
        int subarrays = 1;
        int currSum = 0;
        
        for (int num : arr){
            if (currSum + num > limit){
                subarrays++;
                currSum = num;
            }
            else currSum += num;
        }
        
        return subarrays <= k;
    }
}