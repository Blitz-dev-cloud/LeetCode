class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for( int r = 0 ; r < n ; r++ ) {
            char c = s[r];

            if(c == '(') st.push(r);
            else {
                st.pop();
                if(st.empty()) st.push(r);
                else {
                    maxLen = max(maxLen, r - st.top());
                }
            }
        }

        return maxLen;
    }
};