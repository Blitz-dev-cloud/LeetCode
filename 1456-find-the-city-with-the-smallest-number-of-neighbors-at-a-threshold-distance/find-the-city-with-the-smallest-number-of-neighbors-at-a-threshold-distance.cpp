class Solution {
public:
    //blitz
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int> (n, 1e9));
        for( int i = 0 ; i < n ; i++ ) cost[i][i] = 0;
        for( auto it : edges ){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            cost[u][v] = w;
            cost[v][u] = w;
        }
        for( int via = 0 ; via < n ; via++ ){
            for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
        int minCount = 1e9, node = -1;
        for( int i = 0 ; i < n ; i++ ){
            int count = 0;
            for( int j = 0 ; j < n ; j++ ){
                if(cost[i][j] <= distanceThreshold) count++;
            }
            if(minCount > count || (minCount == count && i > node)){
                minCount = count;
                node = i;
            }
        } 
        return node;         
    }
};