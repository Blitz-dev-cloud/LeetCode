class Solution {
private:
    vector<vector<int>> result;
    void dfs(int node, int n, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path) {
        visited[node] = true;
        path.push_back(node);

        if(node == n - 1) {
            result.push_back(path);
        }

        for( int adjNode : graph[node] ) {
            if(!visited[adjNode]) {
                dfs(adjNode, n, graph, visited, path);
            }
        }

        path.pop_back();
        visited[node] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n, false);
        vector<int> path;

        dfs(0, n, graph, visited, path);

        return result;
    }
};