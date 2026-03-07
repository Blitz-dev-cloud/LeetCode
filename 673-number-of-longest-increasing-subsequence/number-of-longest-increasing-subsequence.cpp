class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxLen = 0;

        vector<pair<int, int>> dp(n, {1, 1});
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < i ; j ++ ) {
                if(nums[i] > nums[j]) {
                    if(dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1) dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }

            if(maxLen == dp[i].first) res += dp[i].second;
            if(maxLen < dp[i].first) {
                maxLen = dp[i].first;
                res = dp[i].second;
            }
        }

        return res;
    }
};