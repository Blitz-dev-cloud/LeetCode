class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, int> freq;

        for( int i = 0 ; i < n ; i++ ) {
            string s = strs[i];
            for( int j = 0 ; j < s.size() ; j++ ) {
                freq[s.substr(0, j + 1)]++;
            }
        }

        int maxLen = 0;
        string ans = "";

        for( auto &f : freq ) {
            auto [key, val] = f;
            // cout << key << " " << val << endl;
            if(val == n && key.size() > maxLen) {
                maxLen = key.size();
                ans = key;
            }
        }

        return ans;
    }
};