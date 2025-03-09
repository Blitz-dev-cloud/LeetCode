class Solution {
public:
    //blitz
    int search(string text1, string text2, int m, int n, vector<vector<int>> &lcs){
        for( int i = 1 ; i <= m ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if(text1[i - 1] == text2[j - 1]){
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else{
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        return lcs[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));
        return search(text1, text2, m, n, lcs);
    }
};