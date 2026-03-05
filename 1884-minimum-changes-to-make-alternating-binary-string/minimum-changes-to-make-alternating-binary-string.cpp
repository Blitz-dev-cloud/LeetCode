class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int op1 = 0, op2 = 0;

        for( int i = 0 ; i < n ; i++ ) {
            char expected_1 = (i % 2 == 0) ? '0' : '1';
            char expected_2 = (i % 2 == 0) ? '1' : '0';

            if(s[i] == expected_1) op1++;
            if(s[i] == expected_2) op2++;
        }

        return min(op1, op2);
    }
};