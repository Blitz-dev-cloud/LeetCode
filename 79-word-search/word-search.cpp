class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool dfs(int i, int j, int idx, int n, int m, vector<vector<char>> &board, string &word, vector<vector<bool>> &visited) {
        if(idx == word.size()) return true;

        visited[i][j] = true;

        for(int k = 0 ; k < 4 ; k++ ) {
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] == word[idx]) {
                if(dfs(nx, ny, idx + 1, n, m, board, word, visited)) return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, n, m, board, word, visited)) return true;
                }
            }
        }
        return false;
    }
};