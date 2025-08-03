class Solution {
public:
    bool isStrictlyIncreasing(const vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; ++i)
            if (nums[i] <= nums[i - 1])
                return false;
        return true;
    }

    bool isStrictlyDecreasing(const vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; ++i)
            if (nums[i] >= nums[i - 1])
                return false;
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for (int p = 1; p < n - 2; ++p) {
            if (!isStrictlyIncreasing(nums, 0, p)) continue;

            for (int q = p + 1; q < n - 1; ++q) {
                if (!isStrictlyDecreasing(nums, p, q)) continue;
                if (!isStrictlyIncreasing(nums, q, n - 1)) continue;
                return true;
            }
        }
        return false;
    }
};