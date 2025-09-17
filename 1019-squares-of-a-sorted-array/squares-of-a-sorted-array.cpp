class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int l = 0, r = n - 1, pos = n - 1;

        while( l <= r ) {
            int lsquare = nums[l] * nums[l];
            int rsquare = nums[r] * nums[r];
            if(lsquare > rsquare) {
                res[pos--] = lsquare;
                l++;
            } else {
                res[pos--] = rsquare;
                r--;
            }
        }

        return res;
    }
};