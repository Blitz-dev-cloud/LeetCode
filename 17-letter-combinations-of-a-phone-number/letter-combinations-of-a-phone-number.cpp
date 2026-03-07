class Solution {
private:
    void solve(string digits, string op, int idx, vector<string> &ans, string mapping[]) {
        if(idx >= digits.size()) {
            ans.push_back(op);
            return;
        }

        int n = digits[idx] - '0';
        string val = mapping[n];

        for( int i = 0 ; i < val.size() ; i++ ) {
            op.push_back(val[i]);
            solve(digits, op, idx + 1, ans, mapping);
            op.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, "", 0, ans, mapping);
        return ans;
    }
};