class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;

        long long shareable = 0;
        for (int day = 2; day <= n; ++day) {
            if (day - delay >= 1) shareable = (shareable + dp[day - delay]) % MOD;
            if (day - forget >= 1) shareable = (shareable - dp[day - forget] + MOD) % MOD;
            dp[day] = shareable;
        }

        long long total = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1) total = (total + dp[day]) % MOD;
        }

        return total;
    }
};