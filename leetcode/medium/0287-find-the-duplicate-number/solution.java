class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        int entry = nums[0];
        while (slow != entry){
            slow = nums[slow];
            entry = nums[entry];
        }
        return entry;
    }
}