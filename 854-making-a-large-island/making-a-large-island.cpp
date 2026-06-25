class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for( int i = 0 ; i < n ; i++ ) parent[i] = i;
    }

    int findParent(int u) {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int p_u = findParent(u);
        int p_v = findParent(v);

        if(p_u == p_v) return;

        if(size[p_u] < size[p_v]) {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        } else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int N = n * m;

        DSU dsu(N);

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == 1) {
                    int node = n * i + j;

                    for( int k = 0 ; k < 4 ; k++ ) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                            int adjNode = n * nx + ny;
                            dsu.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        /*for( int i = 0 ; i < N ; i++ ) {
            cout << dsu.size[i] << " ";
        }
        cout << endl;*/

        int maxSize = *max_element(dsu.size.begin(), dsu.size.end());

        for( int i = 0 ; i < n ; i++ ) { 
            for( int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int sz = 0;
                    for( int k = 0 ; k < 4 ; k++ ) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                            int adjNode = n * nx + ny;
                            int p_node = dsu.findParent(adjNode);
                            if(seen.find(p_node) == seen.end()) {
                                sz += dsu.size[p_node];
                                seen.insert(p_node);
                            }
                        }
                    }
                    maxSize = max(maxSize, sz + 1);
                }
            }
        }

        return maxSize;
    }
};