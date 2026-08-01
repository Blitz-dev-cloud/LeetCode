class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (n, INT_MIN));

        for( int i = 0 ; i < n ; i++ ) {
            dp[i][i] = nums[i];
        }

        for( int len = 2 ; len <= n ; len++ ) {
            for( int l = 0 ; len < n - l + 1 ; l++ ) {
                int r = l + len - 1;
                dp[l][r] = max(nums[l] - dp[l + 1][r], nums[r] - dp[l][r - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};