class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        for( char x : s ) freq[x]++;

        vector<pair<int, char>> carr;
        for( auto& m : freq ) {
            auto [key, value] = m;
            carr.push_back({value, key});
        }

        sort(carr.rbegin(), carr.rend());

        string result = "";
        for( auto& p : carr ) {
            int cnt = p.first;
            char c = p.second;

            while(cnt-- > 0) result += c;
        }

        return result;
    }
};