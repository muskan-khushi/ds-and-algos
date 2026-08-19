class Solution {
  public:
    int lastIndex(string &s) {
        // code here
        int n = s.size();
        for (int i=n-1; i>=0; i--){
            if (s[i] == '1') return i;
        }
        return -1;
    }
};