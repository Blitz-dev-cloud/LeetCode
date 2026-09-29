class Solution {
private:
    /* vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool dfs(int x, int y, int val, vector<vector<char>> &grid, vector<vector<bool>> &visited, vector<vector<bool>> &inPath) {
        visited[x][y] = true;
        inPath[x][y] = true;

        int n = grid.size();
        int m = grid[0].size();

        if(x == n - 1 && y == m - 1 && val == 0) return true;

        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !inPath[nx][ny] && !visited[nx][ny]) {
                int tempVal = (grid[nx][ny] == '(') ? 1 : -1;
                if(val + tempVal < 0) continue;

                if(dfs(nx, ny, val + tempVal, grid, visited, inPath)) return true;
                // val -= (grid[nx][ny] == '(') ? 1 : -1;
            }
        }

        // val -= (grid[x][y] == '(') ? 1 : -1;
        inPath[x][y] = false;
        return false;
    } */
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        /* vector<vector<bool>> visited(n, vector<bool> (m, false));
        vector<vector<bool>> inPath(n, vector<bool> (m, false));

        if(dfs(0, 0, 1, grid, visited, inPath)) return true;

        return false; */

        /* vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));
        dp[1][1] = 1;

        for( int i = 1 ; i <= n ; i++ ) {
            for( int j = 1 ; j <= m ; j++ ) {
                if(i == 1 && j == 1) continue;
                int val = (grid[i - 1][j - 1] == '(') ? 1 : -1;
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + val;
            }
        }

        return dp[n][m] == 0;*/

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>> (m, vector<bool> (n + m, false)));
        dp[0][0][1] = true;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                for( int bal = 0 ; bal < n + m ; bal++ ) {
                    if(!dp[i][j][bal]) continue;

                    if(i + 1 < n) {
                        int newBal = bal + ((grid[i + 1][j] == '(') ? 1 : -1);
                        if(newBal >= 0) {
                            dp[i + 1][j][newBal] = true;
                        }
                    }

                    if(j + 1 < m) {
                        int newBal = bal + ((grid[i][j + 1] == '(') ? 1 : -1);
                        if(newBal >= 0) {
                            dp[i][j + 1][newBal] = true;
                        }
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};