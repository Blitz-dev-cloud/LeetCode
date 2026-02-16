class Solution {
public:
    int reverseBits(int n) {
        uint32_t x = (uint32_t)n;
        uint32_t ans = 0;

        for( int i = 0 ; i < 32 ; i++ ) {
            ans <<= 1;
            ans |= (x & 1);
            x >>= 1;
        }

        return (int)ans;
    }
};