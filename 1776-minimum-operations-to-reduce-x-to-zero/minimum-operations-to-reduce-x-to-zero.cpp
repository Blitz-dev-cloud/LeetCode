class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        /* int l = 0;
        int r = n - 1;

        int X = x;
        int ans = 0;

        while(l <= r && X > 0) {
            if(X >= nums[l] && X >= nums[r]) {
                if(X - nums[l] < X - nums[r]) {
                    X -= nums[l];
                    l++;
                } else {
                    X -= nums[r];
                    r--;
                }
            } else if(X >= nums[l]) {
                X -= nums[l];
                l++;
            } else if(X >= nums[r]) {
                X -= nums[r];
                r--;
            } else return -1;
            
            if(X == 0) return n - (r - l + 1);
        }

        return -1; */

        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if(target < 0) return -1;

        int sum = 0;
        int l = 0;
        int maxLen = INT_MIN;

        for( int r = 0 ; r < n ; r++ ) {
            sum += nums[r];

            while(sum > target) {
                sum -= nums[l];
                l++;
            }

            if(sum == target) maxLen = max(maxLen, r - l + 1);
        }

        return (maxLen == INT_MIN ? -1 : n - maxLen);
    }
};