class Solution {
public:
    //blitz
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int, int>> q;

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for( int i = 0 ; i < 4 ; i++ ){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                }
            }
        }

        int count = 0;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};