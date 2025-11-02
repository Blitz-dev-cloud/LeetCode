class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int first = 1, second = 2, ways = 0;
        for( int i = 3 ; i <= n ; i++ ) {
            ways = first + second;
            first = second;
            second = ways;
        }

        return ways;
    }
};