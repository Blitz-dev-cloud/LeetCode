class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        //int mpath = 0, path = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> directions = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };

        grid[0][0] = 1;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int dist = grid[i][j];

            if(i == n - 1 && j == m - 1) return dist;

            for( auto &dir : directions ) {
                int ni = i + dir[0], nj = j + dir[1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0) {
                    grid[ni][nj] = dist + 1;
                    q.push({ni, nj});
                }
            }
        }

        return -1;
    }
};