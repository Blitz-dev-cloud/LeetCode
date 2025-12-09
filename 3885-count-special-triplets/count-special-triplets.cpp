class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefix(200005, 0), suffix(200005, 0);

        for (int x : nums) suffix[x]++;

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int val = nums[j];
            int target = val * 2;

            suffix[val]--;

            long long leftCount = 0, rightCount = 0;
            if (target < (int)suffix.size()) {
                leftCount = prefix[target];
                rightCount = suffix[target];
            }

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;

            prefix[val]++;
        }

        return ans;
    }
};