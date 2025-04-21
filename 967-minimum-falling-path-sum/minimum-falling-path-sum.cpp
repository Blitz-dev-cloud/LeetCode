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
        //vector<vector<int>> dp(n, vector<int> (n , 0));
        vector<int> front(n, 0);
        for( int i = 0 ; i < n ; i++ ) front[i] = matrix[n - 1][i];
        int dl = 0, d = 0, dr = 0;
        for( int i = n - 2 ; i >= 0 ; i-- ){
            vector<int> curr(n, 0);
            for( int j = 0 ; j < n ; j++ ){
                dl = (j > 0) ? matrix[i][j] + front[j - 1] : INT_MAX;
                d = matrix[i][j] + front[j];
                dr = (j < n - 1) ? matrix[i][j] + front[j + 1] : INT_MAX;
                curr[j] = min({dl, d, dr});
            }
            front = curr;
        }
        return *min_element(front.begin(), front.end());
    }
};