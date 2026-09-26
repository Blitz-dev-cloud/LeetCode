class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int ans = 0;
        vector<int> prev = {intervals[0][0], intervals[0][1]};

        for( int i = 1 ; i < n ; i++ ) {
            if(intervals[i][0] >= prev[1]) {
                prev = {intervals[i][0], intervals[i][1]};
            } else {
                ans++;
            }
        }

        return ans;
    }
};