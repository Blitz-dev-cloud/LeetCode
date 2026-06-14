class Solution {
public:
    bool checkGoodInteger(int n) {
        int digSum = 0, sqSum = 0;

        while(n > 0) {
            int r = n % 10;
            digSum += r;
            sqSum += r * r;
            n /= 10;
        }

        return (sqSum - digSum >= 50);
    }
};