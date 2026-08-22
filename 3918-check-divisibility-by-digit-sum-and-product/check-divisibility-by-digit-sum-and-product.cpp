class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digProd = 1;

        int N = n;
        while(N > 0) {
            int r = N % 10;
            digSum += r;
            digProd *= r;
            N /= 10;
        }

        return n % (digSum + digProd) == 0;
    }
};