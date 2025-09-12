class Solution {
private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j, int prevHeight) {
        int m = heights.size(), n = heights[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || heights[i][j] < prevHeight || ocean[i][j]) return;

        ocean[i][j] = true;

        dfs(heights, ocean, i + 1, j, heights[i][j]);
        dfs(heights, ocean, i, j + 1, heights[i][j]);
        dfs(heights, ocean, i - 1, j, heights[i][j]);
        dfs(heights, ocean, i, j - 1, heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));

        for( int i = 0 ; i < m ; i++ ) {
            dfs(heights, pacific, i, 0, heights[i][0]);
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
        }

        for( int j = 0 ; j < n ; j++ ) {
            dfs(heights, pacific, 0, j, heights[0][j]);
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);
        }

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) { 
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};