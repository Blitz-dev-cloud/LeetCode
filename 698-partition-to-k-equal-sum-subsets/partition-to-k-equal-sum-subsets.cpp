class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for( int x : nums ) sum += x;

        int target = sum / k;

        if(sum % k != 0) return false;

        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for( int mask = 0 ; mask < (1 << n) ; mask++ ) {
            if(dp[mask] == -1) continue;
            for( int last = 0 ; last < n ; last++ ) {
                if(!(mask & (1 << last))) {
                    if(dp[mask] + nums[last] <= target) {
                        int nextMask = mask | (1 << last);

                        if(dp[nextMask] == -1) dp[nextMask] = (dp[mask] + nums[last]) % target;
                    }
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};