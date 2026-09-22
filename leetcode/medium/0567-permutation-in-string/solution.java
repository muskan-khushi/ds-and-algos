class Solution {
    public boolean checkInclusion(String s1, String s2) {
        //find a substring in s2 that has the same length as s1 and contains the exact same characters as s1
        //verify the substring has the same character frequencies as s1
        //sliding window approach - examine each substring of s2 with length equal to s1
        
        //to efficiently track whether current window matches s1
        //counter that starts with the character counts in s1
        //decrement counts for character entering our window
        //and increment count for leaving

        //need -> how many distinct characters still need to be matched
        //when need = 0 done

        int distinctCharsNeeded = 0;
        int[] charFrequency = new int[26];

        for (char ch : s1.toCharArray()){
            int index = ch - 'a';
            charFrequency[index]++;
            if (charFrequency[index] == 1) distinctCharsNeeded++;  
        }

        int patternLength = s1.length();
        int textLength = s2.length();

        int left = 0;
        for (int right = 0; right < textLength; right++){
            int index = s2.charAt(right) - 'a';
            charFrequency[index]--;

            if (charFrequency[index] == 0) distinctCharsNeeded--;

            if (right - left + 1 > patternLength){
                int leftIndex = s2.charAt(left) - 'a';
                if (charFrequency[leftIndex] == 0) distinctCharsNeeded++;
                charFrequency[leftIndex]++;
                left++;
            }

            if (distinctCharsNeeded == 0) return true;
        }
        return false;

    }
}