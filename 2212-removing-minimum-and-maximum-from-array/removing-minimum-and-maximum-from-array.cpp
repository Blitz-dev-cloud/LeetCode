class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;

        int minIdx = 0;
        int maxIdx = 0;

        int minEl = nums[0];
        int maxEl = nums[0];

        for( int i = 1 ; i < n ; i++ ) {
            if(nums[i] < minEl) {
                minEl = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxEl) {
                maxEl = nums[i];
                maxIdx = i;
            }
        }

        cout << minIdx << " " << maxIdx << endl;

        int left = max(minIdx, maxIdx) + 1;
        int right = n - min(minIdx, maxIdx);
        int both = min(minIdx, maxIdx) + 1 + n - max(minIdx, maxIdx);

        return min({left, right, both});
    }
};