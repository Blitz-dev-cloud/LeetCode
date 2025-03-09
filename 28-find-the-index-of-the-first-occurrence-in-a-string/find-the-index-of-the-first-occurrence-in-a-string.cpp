class Solution {
public:
    //blitz
    void construct_lps(string needle, vector<int> &lps){
        int len = 0;
        lps[0] = 0;
        int i = 1;

        while( i < needle.length() ){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            } else{
                if(len != 0){
                    len = lps[len - 1];
                } else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m), res;
        construct_lps(needle, lps);
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m){
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else{
                if(j != 0){
                    j = lps[j - 1];
                } else{
                    i++;
                }
            }
        }
        if(res.size() >= 1){
            return res[0];
        } else{
            return -1;
        }
    }
};