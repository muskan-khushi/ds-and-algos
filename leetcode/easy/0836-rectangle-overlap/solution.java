class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // corners of rec1
        //rec1[0],rec1[1] - top left
        //rec1[2],rec1[1] - top right
        //rec1[0], rec1[3] - bottom left
        //rec1[2],rec1[3] - bottom right

        boolean xOverlap = Math.max(rec1[0],rec2[0]) < Math.min(rec1[2],rec2[2]);
        boolean yOverlap = Math.max(rec1[1],rec2[1]) < Math.min(rec2[3],rec1[3]);

        return xOverlap && yOverlap;
    }
}