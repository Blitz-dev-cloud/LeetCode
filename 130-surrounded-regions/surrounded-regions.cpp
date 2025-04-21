class Solution {
public:
    //blitz
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        //vector<vector<int>> visited(m, vector<int> (n, 0));
        //vector<vector<char>> sol = board;
        queue<pair<int, int>> q;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&  board[i][j] == 'O'){
                    q.push({i, j});
                    board[i][j] = '#';
                    //visited[i][j] = 1;
                }
            }
        }

        vector<int> drow = {-1, 0, +1, 0};
        vector<int> dcol = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for( int i = 0 ; i < 4 ; i++ ){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow > 0 && nrow < m - 1 && ncol > 0 && ncol < n - 1){
                    if(board[nrow][ncol] == 'O'){
                        board[nrow][ncol] = '#';
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }

    }
};