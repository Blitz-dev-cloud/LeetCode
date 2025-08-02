class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size(), n = waterStartTime.size();
        int minFinish = INT_MAX;

        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int finish1 = waterStart + waterDuration[j];

                int waterStartAlt = waterStartTime[j];
                int waterEnd = waterStartAlt + waterDuration[j];
                int landStartAlt = max(waterEnd, landStartTime[i]);
                int finish2 = landStartAlt + landDuration[i];

                minFinish = min({minFinish, finish1, finish2});
            }
        }

        return minFinish;
    }
};