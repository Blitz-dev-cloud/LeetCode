class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int mLen = 0, start = 0;

        for( int i = 0 ; i < s.size() ; i++ ) {
            char c = s[i];

            if(mpp.find(c) != mpp.end() && mpp[c] >= start) start = mpp[c] + 1;

            mpp[c] = i;
            mLen = max(mLen, i - start + 1);
        }

        return mLen;
    }
};