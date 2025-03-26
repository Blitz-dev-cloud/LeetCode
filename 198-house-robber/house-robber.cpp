class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = 0, prev1 = nums[0];
        for( int i = 1 ; i < n ; i++ ){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};