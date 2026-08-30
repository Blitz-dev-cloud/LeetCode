class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int v = times.size();

        vector<vector<pair<int, int>>> adj(n + 1);
        for( int i = 0 ; i < v ; i++ ) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int time = p.first;
            int node = p.second;

            // if(allVisited(visited)) return time;

            for( auto& q : adj[node] ) {
                int nextNode = q.first;
                int t = q.second;

                if(dist[node] + t < dist[nextNode]) {
                    dist[nextNode] = dist[node] + t;
                    pq.push({dist[nextNode], nextNode});
                    // visited[nextNode] = true;
                }
            }
        }

        for( int i = 1 ; i <= n ; i++ ) {
            if(dist[i] == INT_MAX) return -1;
        }

        return *max_element(dist.begin() + 1, dist.end());
    }
};