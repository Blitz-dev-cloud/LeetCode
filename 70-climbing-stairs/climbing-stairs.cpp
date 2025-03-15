class Solution {
public:
    //blitz
    int f(int i, vector<int> &dp){
        if(dp[i] != -1){
            return dp[i];
        }
        if(i == 0 || i == 1){
            return 1;
        }
        return dp[i] = f(i - 1, dp) +  f(i - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};