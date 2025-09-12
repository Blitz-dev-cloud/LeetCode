class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        int fresh = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int minutes = -1;

        while(!q.empty()) {
            int sz = q.size();
            minutes++;

            for( int i = 0 ; i < sz ; i++ ) {
                auto [x, y] = q.front();
                q.pop();

                for( auto &d : dir ) {
                    int nx = x + d[0], ny = y + d[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        if(fresh > 0) return -1;

        return (minutes == -1) ? 0 : minutes;
    }
};