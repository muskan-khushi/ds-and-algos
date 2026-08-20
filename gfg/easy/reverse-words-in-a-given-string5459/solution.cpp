class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        vector<string> words;
        string word = "";
        
        for (char ch : s){
            if (ch == '.'){
                if (!word.empty()){
                    words.push_back(word);
                    word = "";
                }
            }
            else word += ch;
        }
        
        if (!word.empty()){
            words.push_back(word);
        }
        
        string ans = "";
        for (int i = words.size()-1; i>=0; i--){
            ans += words[i];
            
            if (i != 0){
                ans += '.';
            }
        }
        
        return ans;

    }
};