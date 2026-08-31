class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();

        vector<vector<pair<int, int>>> adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

        vector<vector<int>> dist(n, vector<int>  (k + 2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            // int d = p.first;
            int node = p.second.first;
            int steps = p.second.second;

            if(steps == k + 1) continue;

            for( auto& q : adj[node] ) {
                int nextNode = q.first;
                int d = q.second;

                if(steps <= k && dist[node][steps] + d < dist[nextNode][steps + 1]) {
                    dist[nextNode][steps + 1] = dist[node][steps] + d;
                    pq.push({dist[nextNode][steps + 1], {nextNode, steps + 1}});
                }
            }
        }

        int minDist = INT_MAX;

        for( int i = 0 ; i <= k + 1 ; i++ ) {
            if(dist[dst][i] < minDist) {
                minDist = dist[dst][i];
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};