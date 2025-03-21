class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n % 2 == 0){
            x *= x;
            n = n / 2;
        }
        if(n > 0){
            return myPow(x, n - 1) * x;
        } else{
            return myPow(x, n + 1) / x;
        }
    }
};