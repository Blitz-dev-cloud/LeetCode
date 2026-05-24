class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i = 0;

        for( int num : nums ) {
            if(i < k || num != nums[i - k]) {
                nums[i++] = num;
            }
        }

        nums.resize(i);
        return nums;
    }
};