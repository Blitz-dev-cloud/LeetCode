class Solution {
public:
    int findMinPath(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int m, int n){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m - 1 && j == n - 1) return grid[i][j];
        int moveR = INT_MAX;
        if(j + 1 < n) moveR = grid[i][j] + findMinPath(grid, dp, i, j + 1, m, n);
        int moveD = INT_MAX;
        if(i + 1 < m){
            moveD = grid[i][j] + findMinPath(grid, dp, i + 1, j, m, n);
        }
        return dp[i][j] = min(moveR, moveD);
    }
    int minPathSum(vector<vector<int>>& grid) {
        //top-down approach
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return findMinPath(grid, dp, 0, 0, m, n);
    }
};