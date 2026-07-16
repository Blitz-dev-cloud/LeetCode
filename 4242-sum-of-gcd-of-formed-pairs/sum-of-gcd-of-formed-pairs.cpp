class Solution {
private:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxInt = INT_MIN;

        vector<int> sortedGcds;

        for( int i = 0 ; i < n ; i++ ) {
            maxInt = max(maxInt, nums[i]);
            sortedGcds.push_back(gcd(nums[i], maxInt));
        }

        sort(sortedGcds.begin(), sortedGcds.end());

        long long sum = 0;

        for( int i = 0 ; i < n / 2 ; i++ ) {
            sum += gcd(sortedGcds[i], sortedGcds[n - i - 1]);
        }

        return sum;
    }
};