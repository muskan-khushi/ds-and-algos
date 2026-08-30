class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        string s = to_string(n);
        int power = s.size();
        int ans = 0;
        for (int i=0; i< power; i++){
            int digit = s[i] - '0';
            ans += pow(digit, power);
        }
        if (n == ans) return true;
        else return false;
    }
};