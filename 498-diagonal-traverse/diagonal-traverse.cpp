class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<bool>> visited(n, vector<bool> (m, false));
        visited[0][0] = true;

        bool even = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                temp.push_back(mat[i][j]);
            
                if(i + 1 >= 0 && i + 1 < n && !visited[i + 1][j]) {
                    q.push({i + 1, j});
                    visited[i + 1][j] = true;
                }
                if(j + 1 >= 0 && j + 1 < m && !visited[i][j + 1]) {
                    q.push({i, j + 1});
                    visited[i][j + 1] = true;
                }
            }

            if(!even) reverse(temp.begin(), temp.end());

            even = !even;

            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};