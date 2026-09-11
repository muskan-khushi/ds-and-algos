class Solution {
    public int totalNumbers(int[] digits) {
        int n = digits.length;
        boolean[] seen = new boolean[1000];
        int count = 0;

        for (int i=0; i<n; i++){
            if (digits[i] == 0) continue;

            for (int j=0; j<n; j++){
                if (j==i) continue;

                for (int k=0; k<n; k++){
                    if (k==i || j==k || digits[k] % 2 != 0) continue;

                    int number = digits[i]*100 + digits[j]*10 + digits[k];

                    if (!seen[number]){
                        seen[number] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
}