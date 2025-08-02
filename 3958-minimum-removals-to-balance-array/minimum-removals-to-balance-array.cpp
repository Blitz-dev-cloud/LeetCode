class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0, maxKeep = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            int l = i, h = n - 1, j = i;    

            while(l <= h) {
                int m = (l + h) / 2;
                if(nums[m] <= (long long)nums[i] * k) {
                    j = m;
                    l = m  +1;
                } else h = m - 1;
            }

            maxKeep = max(maxKeep, j - i + 1);
        }
        return n - maxKeep;
    }
};