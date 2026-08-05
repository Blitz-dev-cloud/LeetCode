class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        // vector<bool> hasIndegree(n, false);

        for( auto &it : invocations ) {
            adj[it[0]].push_back(it[1]);
            // if(!hasIndegree[it[1]]) hasIndegree[it[1]] = true;
        }

        queue<int> q;
        vector<bool> sus(n, false);

        q.push(k);
        sus[k] = true;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for( auto &adjNode : adj[node] ) {
                if(!sus[adjNode]) {
                    q.push(adjNode);
                    sus[adjNode] = true;
                }
            }
        }

        // for( int i = 0 ; i < n ; i++ ) cout << sus[i] << " ";
        // cout << endl;

        vector<bool> visited(n, false);

        for( int i = 0 ; i < n ; i++ ) {
            if(!sus[i] && i != k) {
                q.push(i);
                visited[i] = true;
            }
        }

        bool flag = false;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(sus[node]) {
                flag = true;
                break;
            }

            for( auto &adjNode : adj[node] ) {
                if(!visited[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = true;
                }
            }
        }

        vector<int> result;

        for( int i = 0 ; i < n ; i++ ) {
            if(flag) {
                result.push_back(i);
                continue;
            } else if(!flag && !sus[i]) result.push_back(i);
        }

        return result;
    }
};