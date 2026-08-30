class Solution {
  public:
  public:
    bool isStrong(int n) {
        // code here.
        int ans = 0;
        string s = to_string(n);
        for (char ch : s){
            int digit = (ch - '0');
            int fact = 1;
            for (int i=1; i<=digit; i++){
                fact *= i;
            }
            ans += fact;
        }
        
        return ans == n;
    }
};
