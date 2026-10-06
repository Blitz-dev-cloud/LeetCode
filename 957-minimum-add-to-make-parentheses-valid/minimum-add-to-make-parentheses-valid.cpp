class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int sum = 0;

        for( char c : s ) {
            if(c == '(') st.push(c);
            else {
                if(st.empty()) sum++;
                else st.pop();
            }
        }

        return sum + st.size();
    }
};