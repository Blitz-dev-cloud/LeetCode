class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        /* sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }); */

        int ans = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n && j != i ; j++ ) {
                if(max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])) ans++;
            }
        }

        return ans;
    }
};