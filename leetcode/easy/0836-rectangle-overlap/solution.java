class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // corners of rec1
        //rec1[0],rec1[1] - top left
        //rec1[2],rec1[1] - top right
        //rec1[0], rec1[3] - bottom left
        //rec1[2],rec1[3] - bottom right

        if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] < rec1[1]) return false;
        return true; 
    }
}