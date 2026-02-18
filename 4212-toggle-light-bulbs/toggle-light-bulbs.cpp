class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();

        map<int, int> freq;
        for( int x : bulbs ) freq[x]++;

        vector<int> res;
        for( auto it : freq ) {
            if(it.second % 2 == 1) res.push_back(it.first);
        }

        return res;
    }
};