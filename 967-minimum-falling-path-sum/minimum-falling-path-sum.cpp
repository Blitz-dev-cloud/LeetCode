class Solution {
public:
    //blitz
    /*int f(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        if(j < 0 || j >= n) return 1e9;
        if(i == n - 1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int dl = 0, d = 0, dr = 0;
        dl = matrix[i][j] + f(i + 1, j - 1, n, dp, matrix);
        d = matrix[i][j] + f(i + 1, j, n, dp, matrix);
        dr = matrix[i][j] + f(i + 1, j + 1, n, dp, matrix);
        return dp[i][j] = min({dl, d, dr});
    }*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n , 0));
        for( int i = 0 ; i < n ; i++ ) dp[n - 1][i] = matrix[n - 1][i];
        int dl = 0, d = 0, dr = 0;
        for( int i = n - 2 ; i >= 0 ; i-- ){
            for( int j = 0 ; j < n ; j++ ){
                dl = (j > 0) ? matrix[i][j] + dp[i + 1][j - 1] : INT_MAX;
                d = matrix[i][j] + dp[i + 1][j];
                dr = (j < n - 1) ? matrix[i][j] + dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = min({dl, d, dr});
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};