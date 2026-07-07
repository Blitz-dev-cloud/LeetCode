class Solution {
private:
    int solve(int start, int end, vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[start] = nums[start];

        if(start == end) {
            return dp[start];
        }

        dp[start + 1] = max(nums[start], nums[start + 1]);

        for( int i = start + 2 ; i <= end ; i++ ) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }
        
        return max(solve(0, n - 2, nums), solve(1, n - 1, nums));
    }
};