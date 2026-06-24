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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int> mpp;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 1 ; j < accounts[i].size() ; j++ ) {
                if(mpp.find(accounts[i][j]) == mpp.end()) {
                    mpp[accounts[i][j]] = i;
                } else {
                    dsu.unionBySize(i, mpp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merged(n);
        for( auto& m : mpp ) {
            auto [key, value] = m;
            int node = dsu.findParent(value);
            merged[node].push_back(key);
        }

        vector<vector<string>> result;
        for( int i = 0 ; i < n ; i++ ) {
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for( string x : merged[i] ) {
                temp.push_back(x);
            }

            result.push_back(temp);
        }

        return result;
    }
};