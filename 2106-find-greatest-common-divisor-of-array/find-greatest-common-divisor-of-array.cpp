class Solution {
private:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
public:
    int findGCD(vector<int>& nums) {
        int l = *max_element(nums.begin(), nums.end());
        int r = *min_element(nums.begin(), nums.end());
        return gcd(l, r);
    }
};