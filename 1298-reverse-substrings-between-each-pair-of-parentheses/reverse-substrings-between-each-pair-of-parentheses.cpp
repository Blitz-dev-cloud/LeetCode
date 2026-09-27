class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<char> st;
        string ans = "";

        for( char c : s ) {
            if(c == ')') {
                while(st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                for( char x : ans ) {
                    st.push(x);
                }
                ans = "";
            } else {
                st.push(c);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};