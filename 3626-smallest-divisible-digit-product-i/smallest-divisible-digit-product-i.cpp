class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            int prod = 1;
            int N = n;

            while(N > 0) {
                int r = N % 10;
                prod *= r;
                N /= 10;
            }

            if(prod % t == 0) return n;

            n++;
        }

        return -1;
    }
};