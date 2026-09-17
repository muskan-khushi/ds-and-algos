class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int left = 0;
        int maxFreq = 0;

        int ans = 0;

        for (int right = 0; right<s.length(); right++){
            int index = s.charAt(right) - 'A';
            freq[index]++;
            maxFreq = Math.max(freq[index], maxFreq);

            while ((right - left + 1) - maxFreq > k){
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            ans = Math.max(right-left+1, ans);
        }
        return ans;
    }
}