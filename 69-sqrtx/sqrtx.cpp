class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;

        int l = 0, h = x - 1, ans = 0;

        while(l <= h) {
            long long mid = (l + h) / 2;
            long long sq = mid * mid;

            if(sq == x) return mid;
            else if(sq < x) {
                ans = mid;
                l = mid + 1;
            } else h = mid - 1;
        }

        return ans;
    }
};