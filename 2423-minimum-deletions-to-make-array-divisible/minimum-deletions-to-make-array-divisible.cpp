class Solution {
private:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];

        for( int i = 1 ; i < numsDivide.size() ; i++ ) g = gcd(g, numsDivide[i]);

        sort(nums.begin(), nums.end());

        for( int i = 0 ; i < nums.size() ; i++ ) {
            if(g % nums[i] == 0) return i;
        }

        return -1;
    }
};