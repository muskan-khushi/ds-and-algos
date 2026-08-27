class Solution {
public:
    int compress(vector<char>& chars) {
        //which position to write
        int write = 0;

        //scan the chars
        int i = 0;

        while (i<chars.size()){
            char currentChar = chars[i];
            int j = i;

            while (j<chars.size() && chars[j] == currentChar){
                j++;
            }

            int count = j-i;

            chars[write] = currentChar;
            write++;

            if (count > 1){
                string countStr = to_string(count);
                for (char ch : countStr){
                    chars[write] = ch;
                    write++;
                }
            }

            i=j;
         }

         return write;
    }
};