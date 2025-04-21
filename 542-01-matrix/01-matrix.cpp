class Solution {
public:
    //blitz
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        vector<vector<int>> distance(m, vector<int> (n, 0));
        queue<pair<pair<int, int>, int>> q;

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<int> drow = {-1, 0, +1, 0};
        vector<int> dcol = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;

            for( int i = 0 ; i < 4 ; i++ ){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0){
                    q.push({{nrow, ncol}, steps + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return distance;
    }
};