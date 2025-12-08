class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            for( int j = 1 ; j <= n ; j++ ) {
                int csq = i * i + j * j;
                int c = sqrt(csq);
                if(c <= n && c * c == csq) count++;
            }
        }
        return count;
    }
};