class Solution {
private:
    vector<vector<int>> result;
    void dfs(int node, int n, vector<vector<int>> &graph, vector<int> &path) {
        path.push_back(node);

        if(node == n - 1) {
            result.push_back(path);
        }

        for( int adjNode : graph[node] ) {
            dfs(adjNode, n, graph, path);
        }

        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> path;

        dfs(0, n, graph, path);

        return result;
    }
};