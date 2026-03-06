class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> indegree(n);
        vector<int> ans;

        for( auto x : prerequisites ) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for( int i = 0 ; i < n ; i++ ) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            ans.push_back(t);

            for( auto x : adj[t] ) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }

        return ans.size() == n;
    }
};