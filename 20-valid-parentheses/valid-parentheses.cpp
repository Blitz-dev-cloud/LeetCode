class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for( char c : s ) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if((c == ')' || c == ']' || c == '}') && st.empty()) {
                return false;
            } else if(c == ')') {
                if(st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            } else if(c == ']') {
                if(st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
            } else if(c == '}') {
                if(st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};