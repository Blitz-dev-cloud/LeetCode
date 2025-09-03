class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        for (int i = 0; i < n; i++) {
            int xa = points[i][0], ya = points[i][1];
            for (int j = i+1; j < n; j++) {
                int xb = points[j][0], yb = points[j][1];

                if (ya >= yb) {
                    bool valid = true;
                    for (int k = i+1; k < j; k++) {
                        int x = points[k][0], y = points[k][1];
                        if (xa <= x && x <= xb && yb <= y && y <= ya) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) ans++;
                }
            }
        }
        return ans;
    }
};