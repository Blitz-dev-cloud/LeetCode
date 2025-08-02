class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<pair<int, int>> nDir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if(grid[i][j] > 0 && !visited[i][j]) {
                    long long sum = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        sum += grid[x][y];

                        for( int i = 0 ; i < 4 ; i++ ) {
                            int dirX = x + nDir[i].first, dirY = y + nDir[i].second;
                            if(dirX >= 0 && dirX < m && dirY >= 0 && dirY < n && 
                            !visited[dirX][dirY] && grid[dirX][dirY] > 0) {
                                visited[dirX][dirY] = true;
                                q.push({dirX, dirY});
                            }
                        }
                    }
                    if(sum % k == 0) count++;
                }
            }
        } 

        return count;
    }
};