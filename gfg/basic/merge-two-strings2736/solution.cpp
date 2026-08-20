class Solution {
  public:
    string merge(string &s1, string &s2) {
        // code here
        int i=0, j=0;
        string ans = "";
        
        while (i < s1.size() || j < s2.size()){
            if (i < s1.size()){
                ans += s1[i];
                i++;
            }
            
            if (j < s2.size()){
                ans += s2[j];
                j++;
            }
        }
        
        return ans;
        
    }
};