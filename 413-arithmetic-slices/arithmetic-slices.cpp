class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int temp = 0, result = 0;

        for( int i = 2 ; i < n ; i++ ) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                temp++;
                result += temp;
            } else temp = 0;
        }

        return result;
    }
};