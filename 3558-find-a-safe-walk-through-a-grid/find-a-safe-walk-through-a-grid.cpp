class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        int init_health = (grid[0][0] == 1 ? health - 1 : health);
        pq.push({init_health, {0, 0}});

        vector<vector<bool>> visited(n, vector<bool> (m, false));
        visited[0][0] = true;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int h = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if(x == n - 1 && y == m - 1 && h >= 1) return true;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny <m && !visited[nx][ny]) {
                    if(grid[nx][ny] == 1) pq.push({h - 1, {nx, ny}});
                    else pq.push({h, {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return false;
    }
};