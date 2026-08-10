class Solution {
private:
    bool canFit(int maxBalls, vector<int> &nums, int maxOperations) {
        long long operations = 0;
        for( int x : nums ) {
            if(x > maxBalls) {
                int k = (1LL * x + maxBalls - 1) / maxBalls;
                operations += k - 1;
            }
        }

        return operations <= maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int ans = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canFit(mid, nums, maxOperations)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};