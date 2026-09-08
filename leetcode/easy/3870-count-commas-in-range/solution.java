class Solution {
    public int countCommas(int n) {
        int count = 0;

        long start = 1000;
        long commas = 1;

        while (start <= n){
            long end = Math.min((long)n, start*1000-1);
            count += end - start + 1;

            start *= 1000;
            commas++;
        }

        return count;
    }
}