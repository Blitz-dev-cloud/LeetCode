class Solution {
private:
    vector<vector<string>> result;
    bool isPalindrome(const string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int idx, int n, string s, vector<string> &curr) {
        if(idx == n) {
            result.push_back(curr);
            return;
        }

        for( int i = idx ; i < n ; i++ ) {
            if(isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, n, s, curr);
                curr.pop_back();    
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> curr;
        backtrack(0, n, s, curr);
        return result;
    }
};