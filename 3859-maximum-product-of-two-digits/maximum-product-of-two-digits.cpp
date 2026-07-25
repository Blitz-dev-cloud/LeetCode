class Solution {
public:
    int maxProduct(int n) {
        int maxEl = INT_MIN;
        int secondMaxEl = INT_MIN;

        while(n > 0) {
            int r = n % 10;
            if(r > maxEl) {
                secondMaxEl = maxEl;
                maxEl = r;
            } else if(r > secondMaxEl) {
                secondMaxEl = r;
            }
            n /= 10;
        }

        return maxEl * secondMaxEl;
    }
};