class DSU {
public:
    vector<int> size, parent;
    vector<int> result = {-1, -1};

    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for( int i = 0 ; i < n ; i++ ) parent[i] = i;
    }

    int findParent(int u) {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int p_u = findParent(u);
        int p_v = findParent(v);

        if(p_u == p_v) {
            result[0] = u;
            result[1] = v;
            return;
        }

        if(size[p_u] < size[p_v]) {
            parent[p_u] = parent[p_v];
            size[p_v] += size[p_u];
        } else {
            parent[p_v] = parent[p_u];
            size[p_u] += size[p_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for( int i = 0 ; i < n ; i++ ) {
            dsu.unionBySize(edges[i][0], edges[i][1]);
        }

        return dsu.result;
    }
};