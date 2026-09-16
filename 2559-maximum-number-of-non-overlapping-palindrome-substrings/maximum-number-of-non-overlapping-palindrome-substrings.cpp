class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r] && (len <= 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; r++) {
            dp[r + 1] = dp[r];

            for (int l = 0; l <= r; l++) {
                int len = r - l + 1;

                if (len >= k && pal[l][r]) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};