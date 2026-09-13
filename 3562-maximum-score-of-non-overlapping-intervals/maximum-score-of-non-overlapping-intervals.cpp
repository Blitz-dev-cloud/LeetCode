class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for( int i = 0 ; i < n ; i++ ) intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        const long long NEG = -(1LL << 60);
        vector<vector<long long>> dp(5, vector<long long> (n, NEG));
        vector<vector<vector<int>>> chosen(5, vector<vector<int>> (n));
        // dp[1][0] = intervals[0][2];

        for( int i = 0 ; i < n ; i++ ) dp[0][i] = 0;

        dp[1][0] = intervals[0][2];
        chosen[1][0] = {intervals[0][3]};

        for( int i = 1 ; i < n ; i++ ) {
            // dp[1][i] = max(dp[1][i - 1], 1LL * intervals[i][2]);
            if(dp[1][i - 1] > intervals[i][2]) {
                dp[1][i] = dp[1][i - 1];
                chosen[1][i] = chosen[1][i - 1];
            } else if(dp[1][i -1] < intervals[i][2]) {
                dp[1][i] = intervals[i][2];
                chosen[1][i] = {intervals[i][3]};
            } else {
                dp[1][i] = dp[1][i - 1];

                vector<int> takeIndices = {intervals[i][3]};

                if(takeIndices < chosen[1][i - 1]) {
                    chosen[1][i] = takeIndices;
                } else {
                    chosen[1][i] = chosen[1][i - 1];
                }
            }
        }

        for( int r = 2 ; r <= 4 ; r++ ) {
            for( int i = 1 ; i < n ; i++ ) {
                int l = 0;
                int h = i - 1;
                int j = -1;

                while(l <= h) {
                    int mid = l + (h - l) / 2;
                    if(intervals[mid][1] < intervals[i][0]) {
                        j = mid;
                        l = mid + 1;
                    } else h = mid - 1;
                }

                // if(j == -1 && r == 1) dp[r][i] = max(dp[1][i - 1], intervals[i][2]);
                if(j == -1 || dp[r - 1][j] == NEG) {
                    dp[r][i] = dp[r][i - 1];
                    chosen[r][i] = chosen[r][i - 1];
                } else {
                    long long take = 1LL * intervals[i][2] + dp[r - 1][j];

                    vector<int> takeIndices = chosen[r - 1][j];
                    takeIndices.push_back(intervals[i][3]);
                    sort(takeIndices.begin(), takeIndices.end());

                    if(take > dp[r][i - 1]) {
                        dp[r][i] = take;
                        chosen[r][i] = takeIndices;
                    } else if(take < dp[r][i - 1]) {
                        dp[r][i] = dp[r][i - 1];
                        chosen[r][i] = chosen[r][i - 1];
                    } else {
                        dp[r][i] = dp[r][i - 1];

                        if(takeIndices < chosen[r][i - 1]) {
                            chosen[r][i] = takeIndices;
                        } else {
                            chosen[r][i] = chosen[r][i - 1];
                        }
                    }
                }
            }
        }

        // cout << max({dp[1][n - 1], dp[2][n - 1], dp[3][n - 1], dp[4][n - 1]}) << endl;

        /* int max_r = -1;
        int max_i = -1;
        long long max_val = 0;

        for( int r = 1 ; r <= 4 ; r++ ) {
            for( int i = 0 ; i < n ; i++ ) {
                if(max_val < dp[r][i]) {
                    max_val = dp[r][i];
                    max_r = r;
                    max_i = i;
                }
            }
        }

        vector<int> ans;
        // ans.push_back(max_i);

        while(max_r >= 1 && max_i >= 0) {
            if(max_i > 0 && dp[max_r][max_i - 1] == dp[max_r][max_i]) {
                // ans.push_back(max_i);
                max_i--;
            } else {
                int l = 0;
                int h = max_i - 1;
                int j = -1;

                while(l <= h) {
                    int mid = l + (h - l) / 2;
                    if(intervals[mid][1] < intervals[max_i][0]) {
                        j = mid;
                        l = mid + 1;
                    } else h = mid - 1;
                }

                ans.push_back(intervals[max_i][3]);
                max_i = j;
                max_r--;
            }
        }

        // reverse(ans.begin(), ans.end());

        sort(ans.begin(), ans.end()); */

        vector<int> ans;
        long long max_val = NEG;

        for( int r = 1 ; r <= 4 ; r++ ) {
            if(dp[r][n - 1] > max_val) {
                max_val = dp[r][n - 1];
                ans = chosen[r][n - 1];
            } else if(dp[r][n - 1] == max_val) {
                if(chosen[r][n - 1] < ans) {
                    ans = chosen[r][n - 1];
                }
            }
        }

        return ans;
    }
};