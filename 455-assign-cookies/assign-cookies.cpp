class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0, j = 0;
        int count = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};