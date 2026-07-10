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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        vector<pair<int, int>> sortedNums(n);
        for( int i = 0 ; i < n ; i++ ) {
            sortedNums[i].first = nums[i];
            sortedNums[i].second = i;
        }

        sort(sortedNums.begin(), sortedNums.end());

        for( int i = 1 ; i < n ; i++ ) {
            if(abs(sortedNums[i - 1].first - sortedNums[i].first) <= maxDiff) dsu.unionBySize(sortedNums[i - 1].second, sortedNums[i].second);
        }

        vector<bool> result;

        for( int i = 0 ; i < queries.size() ; i++ ) {
            int p_u = dsu.findParent(queries[i][0]);
            int p_v = dsu.findParent(queries[i][1]);

            if(p_u == p_v) result.push_back(true);
            else result.push_back(false);
        }

        return result;
    }
};