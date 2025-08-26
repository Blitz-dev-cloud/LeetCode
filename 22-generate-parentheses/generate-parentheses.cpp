class Solution {
private:
    void backtrack(vector<string> &result, string curr, int open, int close, int n) {
        if(curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }

        if(open < n) backtrack(result, curr + "(", open + 1, close, n);

        if(close < open) backtrack(result, curr + ")", open, close + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};