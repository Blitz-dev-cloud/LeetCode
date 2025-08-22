class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int l1 = n, l2 = -1, b1 = m, b2 = -1;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(grid[i][j] == 1) {
                    l1 = min(l1, j);
                    b1 = min(b1, i);
                    l2 = max(l2, j);
                    b2 = max(b2, i);
                }
            }
        }

        if(l2 == -1) return 0;
        return (l2 - l1 + 1) * (b2 - b1 + 1);
    }
};