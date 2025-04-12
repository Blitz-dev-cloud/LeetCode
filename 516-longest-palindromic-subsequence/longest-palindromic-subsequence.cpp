class Solution {
public:
    //blitz
    int lcs(string a, string b){
        int n = a.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else{
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        return lcs(s, revS);
    }
};