class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        for (int num : nums){
            numSet.insert(num);
        }

        int longest = 0;

        for (int num : numSet){
            if (numSet.count(num-1)) continue;
            int length = 1;
            int current = num;
            while (numSet.count(current+1)){
                current++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
        
    }
};