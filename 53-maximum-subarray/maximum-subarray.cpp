class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int msum = nums[0], sum = nums[0];

        for( int i = 1 ; i < n ; i++ ) {
            sum = max(nums[i], sum + nums[i]);
            msum = max(msum, sum);
        }

        return msum;
    }
};