class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        for( int i = 0 ; i < s.size() ; i++ ) {
            degree += (26 - (s[i] - 'a')) * (i + 1);
        }
        return degree;
    }
};