class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b(n);

        string s = b.to_string();

        int ans = 0;
        for( char x : s ) ans += x - '0';

        return ans;
    }
};