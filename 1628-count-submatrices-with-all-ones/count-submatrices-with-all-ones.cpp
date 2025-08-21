class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> heights(m, 0);

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(mat[i][j] == 1) heights[j] += 1;
                else heights[j] = 0;
            }

            for( int j = 0 ; j < m ; j++ ) {
                int minHeight = heights[j];
                for( int k = j ; k >= 0 && minHeight > 0 ; k-- ) {
                    minHeight = min(minHeight, heights[k]);
                    res += minHeight;
                }
            }
        }

        return res;
    }
};