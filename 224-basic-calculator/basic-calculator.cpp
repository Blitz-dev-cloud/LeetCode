class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        stack<int> st;
        long long res = 0;
        long long op = 0, sign = 1;

        for( int i = 0 ; i < n ; i++ ) {
            if(isdigit(s[i])) op = op * 10 + (s[i] - '0');
            else if(s[i] == '+') {
                res += sign * op;
                sign = 1;
                op = 0;
            } else if(s[i] == '-') {
                res += sign * op;
                sign = -1;
                op = 0;
            } else if(s[i] == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            } else if(s[i] == ')') {
                res += sign * op;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
                op = 0;
            }
        }

        return res + (sign * op);
    }
};