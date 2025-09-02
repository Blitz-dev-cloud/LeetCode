class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int n = points.size();
        int res = 0;

        auto inBox = [&](int Ax, int Ay, int Bx, int By, int Cx, int Cy) -> bool {
            return (Ax <= Cx && Cx <= Bx) && (By <= Cy && Cy <= Ay);
        };

        for (int a = 0; a < n; ++a) {
            int Ax = points[a][0], Ay = points[a][1];

            for (int b = 0; b < n; ++b) {
                if (a == b) continue;
                int Bx = points[b][0], By = points[b][1];

                if (Ax > Bx || Ay < By) continue;

                bool blocked = false;
                for (int c = 0; c < n; ++c) {
                    if (c == a || c == b) continue;
                    int Cx = points[c][0], Cy = points[c][1];
                    if (inBox(Ax, Ay, Bx, By, Cx, Cy)) {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) ++res;
            }
        }
        return res;
    }
};