class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxEl = *max_element(nums.begin(), nums.end());
        long long minEl = *min_element(nums.begin(), nums.end());
        return 1LL * (maxEl - minEl) * k;
    }
};