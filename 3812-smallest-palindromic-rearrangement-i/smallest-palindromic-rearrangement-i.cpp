class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        
        string p1 = s.substr(0, n / 2);
        sort(p1.begin(), p1.end());

        string p2 = p1;
        reverse(p2.begin(), p2.end());

        if(n & 1) {
            return p1 + s[n / 2] + p2;
        }
        
        return p1 + p2;
    }
};