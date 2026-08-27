class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < chars.size()){
            char currChar = chars[i];
            int j = i;
            while (j< chars.size() && chars[j] == currChar ){
                j++;
            }
            int count = j - i;

            chars[write] = currChar;
            write++;

            if (count > 1){
                string countStr = to_string(count);
                for (char digit : countStr){
                    chars[write] = digit;
                    write++;
                }
            }

             i = j;
        }   

        return write;     
    }
};