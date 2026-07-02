class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        int k = s1.size();

        for( int i = 0 ; i < k ; i++ ) f1[s1[i] - 'a']++;

        int l = 0, r = 0;

        for( ; r < k ; r++ ) {
            f2[s2[r] - 'a']++;
        }

        if(f1 == f2) return true;

        for( ; r < s2.size() ; r++ ) {
            f2[s2[l++] - 'a']--;
            f2[s2[r] - 'a']++;
            if(f1 == f2) return true;
        }

        return false;
    }
};