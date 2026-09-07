class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        unordered_map<char, int> last;

        int MOD = 1000000007;

        for( int i = 1 ; i <= n ; i++ ) {
            dp[i] = 2 * dp[i - 1] + 1;
            if(last.count(s[i - 1])) {
                dp[i] -= dp[last[s[i - 1]] - 1] + 1;
            }

            dp[i] %= MOD;
            if(dp[i] < 0) dp[i] += MOD;

            last[s[i - 1]] = i;
        }

        return dp[n];
    }
};