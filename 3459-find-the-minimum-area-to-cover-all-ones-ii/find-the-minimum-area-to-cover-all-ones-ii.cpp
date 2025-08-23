class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int n = (int)grid.size(), m = (int)grid[0].size();

        vector<pair<int,int>> ones;
        ones.reserve(n * m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) ones.emplace_back(i,j);

        auto area = [](int minr, int minc, int maxr, int maxc, int cnt)->int{
            if (cnt == 0) return INT_MAX;
            return (maxr - minr + 1) * (maxc - minc + 1);
        };

        auto upd = [](int &minv, int &maxv, int v){
            minv = min(minv, v);
            maxv = max(maxv, v);
        };

        int best = INF;

        for (int c1 = 0; c1 <= m - 3; ++c1) {
            for (int c2 = c1 + 1; c2 <= m - 2; ++c2) {
                int minr[3] = {n, n, n}, maxr[3] = {-1, -1, -1};
                int minc[3] = {m, m, m}, maxc[3] = {-1, -1, -1};
                int cnt[3]  = {0, 0, 0};

                for (auto [i,j] : ones) {
                    int g = (j <= c1) ? 0 : (j <= c2 ? 1 : 2);
                    ++cnt[g];
                    upd(minr[g], maxr[g], i);
                    upd(minc[g], maxc[g], j);
                }
                if (cnt[0] && cnt[1] && cnt[2]) {
                    int sum = area(minr[0],minc[0],maxr[0],maxc[0],cnt[0])
                            + area(minr[1],minc[1],maxr[1],maxc[1],cnt[1])
                            + area(minr[2],minc[2],maxr[2],maxc[2],cnt[2]);
                    best = min(best, sum);
                }
            }
        }

        for (int r1 = 0; r1 <= n - 3; ++r1) {
            for (int r2 = r1 + 1; r2 <= n - 2; ++r2) {
                int minr[3] = {n, n, n}, maxr[3] = {-1, -1, -1};
                int minc[3] = {m, m, m}, maxc[3] = {-1, -1, -1};
                int cnt[3]  = {0, 0, 0};

                for (auto [i,j] : ones) {
                    int g = (i <= r1) ? 0 : (i <= r2 ? 1 : 2);
                    ++cnt[g];
                    upd(minr[g], maxr[g], i);
                    upd(minc[g], maxc[g], j);
                }
                if (cnt[0] && cnt[1] && cnt[2]) {
                    int sum = area(minr[0],minc[0],maxr[0],maxc[0],cnt[0])
                            + area(minr[1],minc[1],maxr[1],maxc[1],cnt[1])
                            + area(minr[2],minc[2],maxr[2],maxc[2],cnt[2]);
                    best = min(best, sum);
                }
            }
        }

        for (int r = 0; r <= n - 2; ++r) {
            for (int c = 0; c <= m - 2; ++c) {

                {
                    int minr0=n, maxr0=-1, minc0=m, maxc0=-1, cnt0=0;
                    int minr1=n, maxr1=-1, minc1=m, maxc1=-1, cnt1=0;
                    int minr2=n, maxr2=-1, minc2=m, maxc2=-1, cnt2=0;
                    for (auto [i,j] : ones) {
                        if (j <= c) {
                            ++cnt0; upd(minr0,maxr0,i); upd(minc0,maxc0,j);
                        } else if (i <= r) {
                            ++cnt1; upd(minr1,maxr1,i); upd(minc1,maxc1,j);
                        } else {
                            ++cnt2; upd(minr2,maxr2,i); upd(minc2,maxc2,j);
                        }
                    }
                    if (cnt0 && cnt1 && cnt2) {
                        int sum = area(minr0,minc0,maxr0,maxc0,cnt0)
                                + area(minr1,minc1,maxr1,maxc1,cnt1)
                                + area(minr2,minc2,maxr2,maxc2,cnt2);
                        best = min(best, sum);
                    }
                }

                {
                    int minr0=n, maxr0=-1, minc0=m, maxc0=-1, cnt0=0;
                    int minr1=n, maxr1=-1, minc1=m, maxc1=-1, cnt1=0;
                    int minr2=n, maxr2=-1, minc2=m, maxc2=-1, cnt2=0;
                    for (auto [i,j] : ones) {
                        if (j > c) {
                            ++cnt0; upd(minr0,maxr0,i); upd(minc0,maxc0,j);
                        } else if (i <= r) {
                            ++cnt1; upd(minr1,maxr1,i); upd(minc1,maxc1,j);
                        } else {
                            ++cnt2; upd(minr2,maxr2,i); upd(minc2,maxc2,j);
                        }
                    }
                    if (cnt0 && cnt1 && cnt2) {
                        int sum = area(minr0,minc0,maxr0,maxc0,cnt0)
                                + area(minr1,minc1,maxr1,maxc1,cnt1)
                                + area(minr2,minc2,maxr2,maxc2,cnt2);
                        best = min(best, sum);
                    }
                }

                {
                    int minr0=n, maxr0=-1, minc0=m, maxc0=-1, cnt0=0; // top
                    int minr1=n, maxr1=-1, minc1=m, maxc1=-1, cnt1=0; // bottom-left
                    int minr2=n, maxr2=-1, minc2=m, maxc2=-1, cnt2=0; // bottom-right
                    for (auto [i,j] : ones) {
                        if (i <= r) {
                            ++cnt0; upd(minr0,maxr0,i); upd(minc0,maxc0,j);
                        } else if (j <= c) {
                            ++cnt1; upd(minr1,maxr1,i); upd(minc1,maxc1,j);
                        } else {
                            ++cnt2; upd(minr2,maxr2,i); upd(minc2,maxc2,j);
                        }
                    }
                    if (cnt0 && cnt1 && cnt2) {
                        int sum = area(minr0,minc0,maxr0,maxc0,cnt0)
                                + area(minr1,minc1,maxr1,maxc1,cnt1)
                                + area(minr2,minc2,maxr2,maxc2,cnt2);
                        best = min(best, sum);
                    }
                }

                {
                    int minr0=n, maxr0=-1, minc0=m, maxc0=-1, cnt0=0;
                    int minr1=n, maxr1=-1, minc1=m, maxc1=-1, cnt1=0;
                    int minr2=n, maxr2=-1, minc2=m, maxc2=-1, cnt2=0;
                    for (auto [i,j] : ones) {
                        if (i > r) {
                            ++cnt0; upd(minr0,maxr0,i); upd(minc0,maxc0,j);
                        } else if (j <= c) {
                            ++cnt1; upd(minr1,maxr1,i); upd(minc1,maxc1,j);
                        } else {
                            ++cnt2; upd(minr2,maxr2,i); upd(minc2,maxc2,j);
                        }
                    }
                    if (cnt0 && cnt1 && cnt2) {
                        int sum = area(minr0,minc0,maxr0,maxc0,cnt0)
                                + area(minr1,minc1,maxr1,maxc1,cnt1)
                                + area(minr2,minc2,maxr2,maxc2,cnt2);
                        best = min(best, sum);
                    }
                }
            }
        }

        return best;
    }
};