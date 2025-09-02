class Solution {
private:
    bool dfs(vector<vector<int>> &grid, int x, int y, int n, int m) {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;

        if(grid[x][y] != 0) return true;

        grid[x][y] = 2;

        bool left =  dfs(grid, x - 1, y, n, m);
        bool up = dfs(grid, x, y + 1, n, m);
        bool right = dfs(grid, x + 1, y, n, m);
        bool down = dfs(grid, x, y - 1, n, m);

        return left && up && right && down;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {    
                if(grid[i][j] == 0) {
                    if(dfs(grid, i, j, n, m)) count++;
                }
            }
        }

        return count;
    }
};