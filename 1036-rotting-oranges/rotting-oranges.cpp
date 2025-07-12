class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector <int>> visited(n, vector<int> (m, 0));
        int countFresh = 0;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                if(grid[i][j] == 1) countFresh++;
            }
        }

        int totalMinutes = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delColumn = {0, 1, 0, -1};
        int count = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            totalMinutes = max(totalMinutes, t);
            q.pop();

            for( int i = 0 ; i < 4 ; i++ ){
                int nRow = r + delRow[i];
                int nCol = c + delColumn[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = 1;
                    count++;
                }
            }
        }

        if(count != countFresh) return -1;

        return totalMinutes;
    }
};