class Solution {
private:
    int result = 0;
    void backtrack(int idx, int n, vector<int> &nums, int target, int sum) {
        if(idx >= n) {
            if(sum == target) {
                result++;
            }
            return;
        }

        int temp = sum;
        sum += nums[idx];
        backtrack(idx + 1, n, nums, target, sum);

        sum = temp;
        sum -= nums[idx];
        backtrack(idx + 1, n, nums, target, sum);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        backtrack(0, n, nums, target, 0);
        return result;
    }
};