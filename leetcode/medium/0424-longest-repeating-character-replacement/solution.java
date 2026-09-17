class Solution {
    public int characterReplacement(String s, int k) {
        //Algorithm
        //Dynamic Sliding Window Pattern
        // kisi bhi window mei jis bhi element ka maxFreq hogaa, window length - maxFreq <= k hona chhaiye

        //store frequency of each element in a particular window
        int[] freq = new int[26];

        //max freq of any element in a window
        int maxFreq = 0;

        //ans storing the max length
        int ans = 0;
        int left = 0;

        //sliding window pattern
        for (int right = 0; right<s.length(); right++){
            int index = s.charAt(right) - 'A';
            freq[index]++;
            maxFreq = Math.max(maxFreq, freq[index]);

           //invalid window, shrink from left
            while ((right-left+1) - maxFreq > k){
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            //valid window
            ans = Math.max(ans, right-left+1);
        }
        return ans;
    }
}