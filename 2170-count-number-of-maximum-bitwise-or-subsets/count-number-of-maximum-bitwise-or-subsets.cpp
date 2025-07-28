class Solution {
private:
    int count = 0;
    int maxOr = 0;
    void backtrack(vector<int> &nums, int index, int currOr) {
        if(index == nums.size()) {
            if(currOr == maxOr) {
                count++;
            }
            return;
        }

        backtrack(nums, index + 1, currOr | nums[index]);

        backtrack(nums, index + 1, currOr);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for( int num : nums ) {
            maxOr |= num;
        }

        backtrack(nums, 0, 0);

        return count;
    }
};