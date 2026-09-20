class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        for (int i=0; i<s.length(); i++){
            int index = 26 - (s.charAt(i) - 'a');
            int pos = i+1;

            ans += index*pos;
        }

        return ans;
    }
}