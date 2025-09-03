class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp = matrix;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                int left = (j > 0) ? dp[i + 1][j - 1] : 1e9;
                int down = dp[i + 1][j];
                int right = (j < m - 1) ? dp[i + 1][j + 1] : 1e9;

                dp[i][j] += min({left, down, right});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};