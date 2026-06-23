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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size()) return -1;
        
        DSU dsu(n);

        for( int i = 0 ; i < connections.size() ; i++ ) {
            dsu.unionBySize(connections[i][0], connections[i][1]);
        }

        int result = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(dsu.parent[i] == i) result++;
        }

        return result - 1;
    }
};