class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            if(!isalnum(s[l])) {
                l++;
                continue;
            }
            else if(!isalnum(s[r])) {
                r--;
                continue;
            }
            else if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};