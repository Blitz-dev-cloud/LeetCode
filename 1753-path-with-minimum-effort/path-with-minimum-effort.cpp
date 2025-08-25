class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pq.empty()) {
            auto [efforts, r, c] = pq.top();
            pq.pop();

            if(r == n - 1 && c == m - 1) return efforts;

            for( auto [dr, dc] : dirs ) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(efforts, abs(heights[nr][nc] - heights[r][c]));
                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                } 
            }
        }

        return -1;
    }
};