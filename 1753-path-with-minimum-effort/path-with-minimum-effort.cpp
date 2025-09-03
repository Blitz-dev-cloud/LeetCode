class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pq.empty()) {
            int x = pq.top().second.first, y = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            if(x == n - 1 && y == m - 1) return effort;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dir[i].first, ny = y + dir[i].second;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    //visited[nx][ny] = true;
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if(newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};