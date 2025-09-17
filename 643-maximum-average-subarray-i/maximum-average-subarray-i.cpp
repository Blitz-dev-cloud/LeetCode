class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for( int i = 0 ; i < k ; i++ ) sum += nums[i];

        double mAvg = (sum / k);

        for( int i = k ; i < n ; i++ ) {
            sum = sum - nums[i - k] + nums[i];
            mAvg = max(mAvg,sum / k);
        }

        return mAvg;
    }
};