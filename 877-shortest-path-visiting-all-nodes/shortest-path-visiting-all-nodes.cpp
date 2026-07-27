class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<bool>> visited(1 << n, vector<bool> (n, false));
        queue<pair<int, int>> q;

        for( int i = 0 ; i < n ; i++ ) {
            q.push({i, 1 << i});
            visited[1 << i][i] = true;
        }

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz-- > 0) {
                auto [node, mask] = q.front();
                q.pop();

                if(mask == (1 << n) - 1) {
                    return steps;
                }

                for( int nextNode : graph[node] ) {
                    int nextMask = mask | (1 << nextNode);

                    if(!visited[nextMask][nextNode]) {
                        q.push({nextNode, nextMask});
                        visited[nextMask][nextNode] = true;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};