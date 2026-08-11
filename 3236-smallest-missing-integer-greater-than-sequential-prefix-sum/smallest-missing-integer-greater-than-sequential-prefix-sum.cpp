class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int maxSum = nums[0];
        int maxLen = 1;
        int sum = nums[0];

        for( int r = 1 ; r < n ; r++ ) {
            if(nums[r] - nums[r - 1] != 1) {
                break;
            }

            sum += nums[r];
            maxSum = max(maxSum, sum);
        }

        sort(nums.begin(), nums.end());

        for( int x : nums ) {
            if(x == maxSum) maxSum++;
        }

        return maxSum;
    }
};