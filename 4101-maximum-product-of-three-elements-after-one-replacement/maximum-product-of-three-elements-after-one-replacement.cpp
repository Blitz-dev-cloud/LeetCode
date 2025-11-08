class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        const int LIMIT = 100000;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = LLONG_MIN;

        auto getMaxProd = [&](vector<int>& arr) -> long long {
            int m = arr.size();
            long long p1 = 1LL * arr[m - 1] * arr[m - 2] * arr[m - 3];
            long long p2 = 1LL * arr[0] * arr[1] * arr[m - 1];
            return max(p1, p2);
        };

        for (int i = 0; i < min(3, n); ++i) {
            for (int val : {-LIMIT, LIMIT}) {
                vector<int> temp = nums;
                temp[i] = val;
                sort(temp.begin(), temp.end());
                ans = max(ans, getMaxProd(temp));
            }
        }

        for (int i = max(0, n - 3); i < n; ++i) {
            for (int val : {-LIMIT, LIMIT}) {
                vector<int> temp = nums;
                temp[i] = val;
                sort(temp.begin(), temp.end());
                ans = max(ans, getMaxProd(temp));
            }
        }

        return ans;
    }
};