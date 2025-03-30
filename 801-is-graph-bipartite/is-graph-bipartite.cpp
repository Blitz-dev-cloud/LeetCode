class Solution {
    //blitz
private:
    bool checkIfBipartite(int s, int n, vector<vector<int>> &graph, vector<int> &color, int col){
        color[s] = col;

        for( auto it : graph[s] ){
            if(color[it] == -1){
                if(!checkIfBipartite(it, n, graph, color, !col)) return false;
            } else if(color[it] == color[s]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> color(n, -1);

        for( int i = 0 ; i < n ; i++ ){
            if(color[i] == -1){
                if(!checkIfBipartite(i, n, graph, color, 0)) return false;
            }
        }

        return true;
    }
};