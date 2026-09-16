class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || s.length() < p.length()) return result;

        int[] pCount = new int[26];
        int[] sCount = new int[26];

        for (int i=0; i<p.length(); i++){
            pCount[p.charAt(i) - 'a']++;
            sCount[s.charAt(i) - 'a']++;
        }

        if (Arrays.equals(pCount, sCount)) result.add(0);

        for (int i=p.length(); i<s.length(); i++){
            char entering = s.charAt(i);
            sCount[entering - 'a']++;

            char leaving = s.charAt(i-p.length());
            sCount[leaving - 'a']--;

            if (Arrays.equals(pCount, sCount)) result.add(i-p.length()+1);
        }

        return result;
    }
}