class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefProd = 1, suffProd = 1;
        vector<int> result(n, 1);

        for( int i = 0 ; i < n ; i++ ) {
            result[i] *= prefProd;
            prefProd *= nums[i];
        }

        for( int i = n - 1 ; i >= 0 ; i-- ) {
            result[i] *= suffProd;
            suffProd *= nums[i];
        }

        return result;
    }
};