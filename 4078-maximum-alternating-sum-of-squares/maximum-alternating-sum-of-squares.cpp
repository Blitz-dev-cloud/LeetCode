class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return abs(a) > abs(b);
        });

        int l = 0;
        int r = n - 1;

        long long sum = 0;

        while(l < r) {
            sum += 1LL * nums[l] * nums[l] - 1LL * nums[r] * nums[r];
            l++;
            r--;
        }

        if(l == r) sum += 1LL * nums[l] * nums[l];

        return sum;
    }
};