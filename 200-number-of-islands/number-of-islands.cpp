class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();

        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '0') return;

        grid[i][j] = '0';

        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};