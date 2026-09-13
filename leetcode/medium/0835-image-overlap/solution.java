class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        List<int[]> ones1 = new ArrayList<>();
        List<int[]> ones2 = new ArrayList<>();

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (img1[i][j] == 1){
                    ones1.add(new int[]{i,j});
                }
                if (img2[i][j] == 1){
                    ones2.add(new int[]{i,j});
                }
            }
        }

        HashMap<String, Integer> map = new HashMap<>();

        int maxOverlap = 0;

        for (int[] p1 : ones1){
            for (int[] p2 : ones2){
                int r1 = p1[0];
                int r2 = p2[0];

                int c1 = p1[1];
                int c2 = p2[1];

                int rowshift = r2-r1;
                int colshift = c2-c1;

                String key = rowshift + "," + colshift;

                int count = map.getOrDefault(key, 0) + 1;
                map.put(key, count);

                maxOverlap = Math.max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
}