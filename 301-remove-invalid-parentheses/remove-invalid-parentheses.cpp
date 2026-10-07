class Solution {
private:
    set<string> ans;
    int maxLen = 0;
    void backtrack(int idx, int open, int close, int l, int r, string curr, string& s) {
        if(idx == s.size()) {
            if(open == close && l == 0&& r == 0) {
                ans.insert(curr);
            }
            return;
        }

        if(s[idx] >= 'a' && s[idx] <= 'z') backtrack(idx + 1, open, close, l, r, curr + s[idx], s);
        else if(s[idx] == '(') {
            if(l > 0) backtrack(idx + 1, open, close, l - 1, r, curr, s);
            backtrack(idx + 1, open + 1, close, l, r, curr + '(', s);
        } else if(s[idx] == ')') {
            if(r > 0) backtrack(idx + 1, open, close, l, r - 1, curr, s);
            if(open > close) backtrack(idx + 1, open, close + 1, l, r, curr+ ')', s);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        int l = 0;
        int r = 0;

        for( char c : s ) {
            if(c == '(') {
                l++;
            } else if(c == ')') {
                if(l > 0) l--;
                else r++;
            }
        }
        backtrack(0, 0, 0, l, r, "", s);
        return vector<string> (ans.begin(), ans.end());
    }
};