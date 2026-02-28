class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1000000007;
        long long res = 0;
        int length = 0;

        for( int i = 1 ; i <= n ; i++ ) {
            if((i & (i - 1)) == 0) length++;

            res = ((res << length) % MOD + i) % MOD;
        }

        return res;
    }
};