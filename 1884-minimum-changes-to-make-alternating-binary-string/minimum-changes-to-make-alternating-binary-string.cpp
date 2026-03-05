class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string alt_s_1 = "", alt_s_2 = "";
        bool flag = true;
        for( int i = 0 ; i < n ; i++ ) {
            if(flag) {
                alt_s_1 += "0";
                alt_s_2 += "1";
            } else {
                alt_s_1 += "1";
                alt_s_2 += "0"; 
            }
            flag = !flag;
        }

        int op1 = 0, op2 = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == alt_s_1[i]) op1++;
            if(s[i] == alt_s_2[i]) op2++;
        }

        return min(op1, op2);
    }
};