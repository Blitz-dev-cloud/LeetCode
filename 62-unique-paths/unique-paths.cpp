class Solution {
public:
    //blitz
    /*int f(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int d = 0, r = 0;
        if(i < m - 1) d = f(i + 1, j, m, n, dp);
        if(j < n - 1) r = f(i, j + 1, m, n, dp);
        return dp[i][j] = d + r;
    } -> by memoization*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for( int i = 0 ; i < m ; i++ ) dp[i][0] = 1;
        for( int j = 0 ; j < n ; j++ ) dp[0][j] = 1;
        int r = 0, d = 0;
        for( int i = 1 ; i < m ; i++ ){
            for( int j = 1 ; j < n ; j++ ){
                if(i < m) d = dp[i - 1][j];
                if(j < n) r = dp[i][j - 1];
                dp[i][j] = d + r;
            }
        }
        return dp[m - 1][n - 1];
    } /* -> by tabulation*/
};