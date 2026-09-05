class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n, INT_MIN);
        vector<int> suffixMin(n, INT_MAX);

        prefixMax[0] = nums[0];
        suffixMin[n - 1] = nums[n - 1];

        for( int i = 1 ; i < n ; i++ ) prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        for( int i = n - 2 ; i >= 0 ; i-- ) suffixMin[i] = min(suffixMin[i + 1], nums[i]);

        for( int i = 0 ; i < n ; i++ ) {
            if(prefixMax[i] - suffixMin[i] <= k) return i;
        }

        return -1;
    }
};