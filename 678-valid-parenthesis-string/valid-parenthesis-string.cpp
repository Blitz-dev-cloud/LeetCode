class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> st;
        stack<int> stars;

        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];

            if(c == '(') st.push(i);
            else if(c == '*') stars.push(i);
            else if(c == ')') {
                if(!st.empty()) st.pop();
                else if(!stars.empty()) stars.pop();
                else return false;
            }
        }

        while(!st.empty()) {
            if(stars.empty()) return false;

            if(st.top() > stars.top()) return false;

            st.pop();
            stars.pop();
        }

        return true;
    }
};