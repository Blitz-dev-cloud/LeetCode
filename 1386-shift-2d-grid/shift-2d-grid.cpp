class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int N = m * n;

        k %= N;

        vector<int> result(N);

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                result[i * n + j] = grid[i][j];
            }
        }

        reverse(result.begin(), result.end());
        reverse(result.begin(), result.begin() + k);
        reverse(result.begin() + k, result.end());

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                grid[i][j] = result[i * n + j];
            }
        }

        return grid;
    }
};