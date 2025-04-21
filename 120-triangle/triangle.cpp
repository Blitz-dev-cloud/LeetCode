class Solution {
public:
    //blitz
    int f(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i == n - 1) return grid[n - 1][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = 0, dr = 0;
        d = grid[i][j] + f(i + 1, j, n, dp, grid);
        dr = grid[i][j] + f(i + 1, j + 1, n, dp, grid);
        return dp[i][j] = min(d, dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, 0, n, dp, triangle);
    }
};