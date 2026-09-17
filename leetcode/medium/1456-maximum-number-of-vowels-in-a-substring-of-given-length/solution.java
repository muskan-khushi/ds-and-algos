class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int left = 0;
        int vowelCount = 0;
        int maxCount = 0;
        for (int right = 0; right<n; right++){
            if (s.charAt(right) == 'a' || s.charAt(right) == 'e' || s.charAt(right) == 'i' || s.charAt(right) == 'o' || s.charAt(right) == 'u') vowelCount++;

            if (right-left+1 == k){
                maxCount = Math.max(vowelCount, maxCount);
                if (s.charAt(left) == 'a' ||
                    s.charAt(left) == 'e' ||
                    s.charAt(left) == 'i' ||
                    s.charAt(left) == 'o' ||
                    s.charAt(left) == 'u') {

                    vowelCount--;
                }
                left++;
            }
        }
        return maxCount;
    }
}