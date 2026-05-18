class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> hashMap;
        for( int i = 0 ; i < n ; i++ ) {
            hashMap[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        int cnt = INT_MAX;

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int idx = p.first, c = p.second;
            
            if(idx == n - 1) cnt = min(cnt, c);

            if(hashMap[arr[idx]].size() > 1) {
                int sz = hashMap[arr[idx]].size();
                for( int i = sz - 1 ; i >= 0 ; i-- ) {
                    int id = hashMap[arr[idx]][i];
                    if(!visited[id]) {
                        q.push({id, c + 1});
                        visited[id] = true;
                    }
                }
            } 

            hashMap[arr[idx]].clear();

            if(idx - 1 >= 0 && !visited[idx - 1]) {
                q.push({idx - 1, c + 1});
                visited[idx - 1] = true;
            }
            if(idx + 1 < n && !visited[idx + 1]) {
                q.push({idx + 1, c + 1});
                visited[idx + 1] = true;
            }
        }

        return cnt;
    }
};