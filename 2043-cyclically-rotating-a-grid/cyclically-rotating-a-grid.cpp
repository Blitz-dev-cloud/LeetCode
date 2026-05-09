class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> temp;

            int top = layer, left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            for (int j = left; j <= right; j++) temp.push_back(grid[top][j]);
            for (int i = top + 1; i <= bottom - 1; i++) temp.push_back(grid[i][right]);
            for (int j = right; j >= left; j--) temp.push_back(grid[bottom][j]);
            for (int i = bottom - 1; i >= top + 1; i--) temp.push_back(grid[i][left]);

            int len = temp.size();
            int rot = k % len;

            reverse(temp.begin(), temp.begin() + rot);
            reverse(temp.begin() + rot, temp.end());
            reverse(temp.begin(), temp.end());

            int idx = 0;

            for (int j = left; j <= right; j++) grid[top][j] = temp[idx++];
            for (int i = top + 1; i <= bottom - 1; i++) grid[i][right] = temp[idx++];
            for (int j = right; j >= left; j--) grid[bottom][j] = temp[idx++];
            for (int i = bottom - 1; i >= top + 1; i--) grid[i][left] = temp[idx++];
        }

        return grid;
    }
};