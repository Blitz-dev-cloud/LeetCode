class Solution {
public:
    public:
    bool is_safe(vector<int> &cols, int r, int c) {
        for (int i = 0; i < r; i++) {
            if (cols[i] == c || abs(cols[i] - c) == abs(i - r)) {
                return false;
            }
        }
        return true;
    }

    void place_queens(int r, int n, vector<int> &cols, vector<vector<string>> &ans) {
        if (r == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][cols[i]] = 'Q';
            }
            ans.push_back(board);  // Store the valid board configuration
            return;
        }

        for (int i = 0; i < n; i++) {
            if (is_safe(cols, r, i)) {
                cols[r] = i;
                place_queens(r + 1, n, cols, ans);  // Continue placing next queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> cols(n, -1);
        place_queens(0, n, cols, ans);
        return ans;
    }
};