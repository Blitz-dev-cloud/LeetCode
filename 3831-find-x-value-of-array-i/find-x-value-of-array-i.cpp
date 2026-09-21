class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> dp(k, 0);
        // if(nums[0] % k < k) dp[nums[0] % k] = 1;
        vector<long long> ans(k, 0);

        for( int i = 0 ; i < n ; i++ ) {
            vector<long long> newDp(k, 0);
            for( int r = 0 ; r < k ; r++ ) {
                newDp[(r * (nums[i] % k)) % k] += dp[r];
            }
            newDp[nums[i] % k]++;

            for( int r = 0 ; r < k ; r++ ) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};