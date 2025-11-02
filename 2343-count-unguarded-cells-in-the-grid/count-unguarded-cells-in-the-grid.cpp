class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));

        for( auto &a : guards ) {
            int r = a[0], c = a[1];
            grid[r][c] = 1;
        }

        for( auto &a : walls ) {
            int r = a[0], c = a[1];
            grid[r][c] = 2;
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for( auto &a : guards ) {
            int r = a[0], c = a[1];
            for( auto &d : dir ) {
                int dx = d.first, dy = d.second;
                int nx = r + dx, ny = c + dy;
                while( nx >= 0 && nx < m && ny >= 0 && ny < n &&
                 grid[nx][ny] != 1 && grid[nx][ny] != 2 ) {
                    if(grid[nx][ny] == 0) grid[nx][ny] = 3;
                    nx += dx;
                    ny += dy;
                }
            }
        }

        int ans = 0;

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if(grid[i][j] == 0) ans++;
            }
        }

        return ans;
    }
};