class Solution {
    public int maxVowels(String s, int k) {
        int left = 0;
        int vowelCount = 0;
        int maxCount = 0;

        for (int right = 0; right < s.length(); right++){
            if (isVowel(s.charAt(right))) vowelCount++;
            if (right - left + 1 == k){
                maxCount = Math.max(maxCount, vowelCount);
                if (isVowel(s.charAt(left))) vowelCount--;
                left++;
            }
        }

        return maxCount;
    }

    private boolean isVowel(char c){
        return c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u';
    }
}