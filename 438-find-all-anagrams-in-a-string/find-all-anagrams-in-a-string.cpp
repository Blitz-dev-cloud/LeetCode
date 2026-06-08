class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();

        vector<int> result;

        vector<int> p_window(26, 0);
        for( char x : p ) p_window[x - 'a']++;

        vector<int> s_window(26, 0);
        for( char x : s.substr(0, k) ) s_window[x - 'a']++;

        if(s_window == p_window) result.push_back(0);

        int l = 0;

        for( int r = k ; r < n ; r++ ) {
            s_window[s[l] - 'a']--;
            s_window[s[r] - 'a']++;
            l++;

            if(s_window == p_window) result.push_back(l);
        }

        return result;
    }
};