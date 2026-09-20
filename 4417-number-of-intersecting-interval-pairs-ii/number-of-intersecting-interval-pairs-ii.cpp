class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        long long ans = 0;

        for( int i = 0 ; i < n ; i++ ) {
            int l = 0;
            int r = n - 1;

            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(intervals[mid][0] > intervals[i][1]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans += l - i - 1;
        }

        return ans;
    }
};