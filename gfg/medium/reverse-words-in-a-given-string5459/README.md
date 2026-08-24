# reverse-words-in-a-given-string5459

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T06:40:13.275Z  

```cpp
class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        int n = s.size();
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
        
        if (!word.empty()) words.push_back(word);
        
        string ans = "";
        for (int i=words.size()-1; i>=0; i--){
            ans += words[i];
            if (i != 0) ans.push_back('.');
        }
        
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1)