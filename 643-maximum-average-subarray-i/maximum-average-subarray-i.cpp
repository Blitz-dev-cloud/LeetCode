class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        for( int i = 0 ; i < k ; i++ ) sum += nums[i];

        double maxAvg = sum / (double) k;

        int l = 0;
        int r = k;

        while(r < n) {
            sum -= nums[l];
            sum += nums[r];
            maxAvg = max(maxAvg, sum / (double) k);
            l++;
            r++;
        }

        return maxAvg;
    }
};