class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int count = 0;
        for (int i : arr){
            if (i == target) count++;
        }
        
        return count;
    }
};
