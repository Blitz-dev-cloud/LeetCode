class Solution {
private:
    void backtrack(int open, int close, string temp, int n, vector<string> &ans) {
        if(temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if(open < n) {
            backtrack(open + 1, close, temp + '(', n, ans);
        }

        if(close < open) {
            backtrack(open, close + 1, temp + ')', n, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, "", n, ans);
        return ans;
    }
};