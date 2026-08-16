class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        int c0 = 0, c1 = 0, c2 = 0;

        for( int i = 0 ; i < n ; i++ ) {
            stones[i] %= 3;
            if(stones[i] == 0) c0++;
            else if(stones[i] == 1) c1++;
            else if(stones[i] == 2) c2++;
        }

        /* sort(stones.rbegin(), stones.rend());

        bool isDivBy3 = false, turn = false;

        int l = 0, r = n - 1;
        long long sum = 0;

        while(l <= r) {
            if(isDivBy3) sum += stones[l++];
            else sum += stones[r--];

            if(sum % 3 == 0) return isDivBy3;
            isDivBy3 = !isDivBy3;
        } */

        // if(c1 == 0 && c2 == 0) return false;

        if(c0 % 2 == 0) {
            return c1 >= 1 && c2 >= 1;
        }

        return abs(c1 - c2) > 2;
    }
};