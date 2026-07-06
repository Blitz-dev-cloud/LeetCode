struct Edge {
    int v, w;
};

class Solution {
private:
    int minLen = INT_MAX;
    void dfs(int node, int n, vector<bool> &visited, vector<vector<Edge>> &adj) {
        visited[node] = true;

        for( auto &adjNode : adj[node] ) {
            minLen = min(minLen, adjNode.w);
            if(!visited[adjNode.v]) {
                dfs(adjNode.v, n, visited, adj);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();

        vector<vector<Edge>> adj(n + 1);

        for( int i = 0 ; i < m ; i++ ) {
            Edge temp;
            int u = roads[i][0];
            temp.v = roads[i][1];
            temp.w = roads[i][2];
            adj[u].push_back(temp);
            adj[temp.v].push_back({u, temp.w});
        }

        vector<bool> visited(n + 1, false);
        dfs(1, n, visited, adj);

        return minLen;
    }
};