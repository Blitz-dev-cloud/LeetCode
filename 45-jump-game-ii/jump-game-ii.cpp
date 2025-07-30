class Solution {
private:
    int f(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx == nums.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int minJumps = INT_MAX;

        for( int i = 1 ; i <= nums[idx] ; i++ ) {
            int nextJump = idx + i;
            if(nextJump < nums.size()) {
                int subRes = f(idx + i, nums, dp);
                if(subRes != INT_MAX) {
                    minJumps = min(minJumps, 1 + subRes);
                }
            }
        }

        return dp[idx] = minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};