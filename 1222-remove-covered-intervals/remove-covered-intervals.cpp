class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for( int i = 1 ; i < n ; i++ ) {
            if(result.back()[0] >= intervals[i][0] && result.back()[1] <= intervals[i][1]) {
                result.back()[0] = intervals[i][0];
                result.back()[1] = intervals[i][1];
            } else if(result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1]) {
                continue;
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result.size();
    }
};