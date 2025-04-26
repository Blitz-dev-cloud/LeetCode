class Solution {
public:
    //blitz
    /*int f(int i, int j, string p, string t, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[i - 1] == t[j - 1]) return dp[i][j] = 1 + f(i - 1, j - 1, p, t, dp);
        return dp[i][j] = 0 + max(f(i - 1, j, p, t, dp), f(i, j - 1, p, t, dp));
    }*/
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for( int i = 1 ; i <= m ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else{
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};