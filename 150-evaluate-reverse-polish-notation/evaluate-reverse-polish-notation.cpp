class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int res = 0;
        stack<int> st;

        for( int i = 0 ; i < n ; i++ ) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = 0;
                if(tokens[i] == "+") z = x + y;
                else if(tokens[i] == "-") z = y - x;
                else if(tokens[i] == "*") z = x * y;
                else z = y / x;
                st.push(z);
            } else {
                st.push(stoi(tokens[i]));
            }
        }

        res = st.top();
        st.pop();
        return res;
    }
};