class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for( int i = 0 ; i < num ; i++ ) {
            for( int x = 9 ; x >= 0 ; x-- ) {
                if(sum - x >= 0) {
                    sum -= x;
                    ans += x + '0';
                    break;
                }
            }
        }

        return sum == 0 ? ans : "";
    }
};