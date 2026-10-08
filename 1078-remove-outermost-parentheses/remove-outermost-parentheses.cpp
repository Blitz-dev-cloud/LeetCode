class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int deg = 0;

        string temp = "";
        string ans = "";

        for( char c : s ) {
            if(c == '(') {
                if(deg > 0) {
                    st.push(c);
                }
                deg++;
            } else {
                if(deg == 1) {
                    while(!st.empty()) {
                        temp += st.top();
                        st.pop();
                    }
                    deg--;
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    temp.clear();
                } else {
                    st.push(c);
                    deg--;
                }
            }
        }

        // reverse(ans.begin(), ans.end());
        return ans;
    }
};