class Solution {
public:
    //blitz
    int f(int i, int j, int m,int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int r = 0, d = 0;
        if(i < m - 1 && grid[i + 1][j] == 0) d = f(i + 1, j, m, n, dp, grid);
        if(j < n - 1 && grid[i][j + 1] == 0) r = f(i, j + 1, m, n, dp, grid);
        return dp[i][j] = d + r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(0, 0, m, n, dp, obstacleGrid);
    }
};