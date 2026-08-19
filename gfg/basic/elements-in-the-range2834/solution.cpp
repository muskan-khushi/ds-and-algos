class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_set<int> s(arr.begin(), arr.end());
        
        for (int x = start; x<=end; x++){
            if (s.find(x) == s.end()) return false;
        }
        
        
        return true;
    }
};
