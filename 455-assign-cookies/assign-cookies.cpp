class Solution {
public:
    //blitz
    static bool comp(const int &a, const int &b){
        return a > b;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), comp);
        sort(s.begin(), s.end(), comp);
        int max_cookies = 0;
        for( int i = 0, j = 0 ; i < g.size() && j < s.size() ; i++ ){
            if(s[j] >= g[i]){
                max_cookies++;
                j++;
            }
        }
        return max_cookies;
    }
};