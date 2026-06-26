class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(n, vector<bool> (n, false));
        visited[0][0] = true;

        int t = grid[0][0];

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int time = p.first;
            int x = p.second.first;
            int y = p.second.second;

            t = max(t, time);

            if(x == n - 1 && y == n - 1) return t;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                int minTime = INT_MAX;
                int minX = -1;
                int minY = -1;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if(grid[nx][ny] < minTime) {
                        minTime = grid[nx][ny];
                        minX = nx;
                        minY = ny;
                    }
                }
                pq.push({minTime, {minX, minY}});
            }
        }

        return t;
    }
};