class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for( char ch : s ) {
            if(ch == '(' || ch == '{' || ch =='[') st.push(ch);
            else {
                if(st.empty()) return false;
                else if(ch == ')') {
                    if(st.top() != '(') return false;
                    else st.pop();
                } else if(ch == '}') {
                    if(st.top() != '{') return false;
                    else st.pop();
                } else if(ch == ']') {
                    if(st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
        return st.empty();
    }
};