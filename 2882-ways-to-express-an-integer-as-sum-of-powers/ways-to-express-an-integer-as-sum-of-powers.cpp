class Solution {
private:
    const int MOD = 1'000'000'007;
    long long intPow(int base, int exp) {
        long long res = 1;
        while (exp--) res *= base;
        return res;
    }
    int f(int idx, int sum, int n, int x, vector<vector<int>> &dp) {
        if(sum > n) return 0;
        if(sum == n) return 1;

        long long p = intPow(idx, x);
        if(p > n) return 0;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int pick = 0;
        if(sum + p <= n) pick = (pick + f(idx + 1, sum + p, n, x, dp)) % MOD;
        pick = (pick + f(idx + 1, sum, n, x, dp)) % MOD;

        return dp[idx][sum] = pick;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 2, vector<int> (n + 1, -1));
        //int total = 0;
        return f(1, 0, n, x, dp);
        //return total;
    }
};