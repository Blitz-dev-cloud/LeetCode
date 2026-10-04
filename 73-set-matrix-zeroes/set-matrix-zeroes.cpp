class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> zeros;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(matrix[i][j] == 0) zeros.push_back({i, j});
            }
        }

        // vector<int> dx = {-1, 0, 1, 0};
        // vector<int> dy = {0, 1, 0, -1};

        for( auto &z : zeros ) {
            int x = z.first;
            int y = z.second;

            for( int j = 0 ; j < m ; j++ ) {
                if(matrix[x][j] != 0) matrix[x][j] = 0;
            }

            for( int i = 0 ; i < n ; i++ ) {
                if(matrix[i][y] != 0) matrix[i][y] = 0;
            }
        }

        // return matrix;
    }
};