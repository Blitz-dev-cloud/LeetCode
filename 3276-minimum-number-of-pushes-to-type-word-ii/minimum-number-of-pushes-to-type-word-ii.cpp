class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<char, int>> freq;
        vector<int> visited(26, -1);

        int idx = 0;

        for( char x : word ) {
            if(visited[x - 'a'] == -1) {
                freq.push_back({x, 1});
                visited[x - 'a'] = idx++;
            } else {
                int i = visited[x - 'a'];
                freq[i].second++;
            }
        }

        sort(freq.begin(), freq.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second;
        });

        int factor = 0;
        int sum = 0;

        for( int i = 0 ; i < freq.size() ; i++ ) {
            if(i % 8 == 0) factor++;
            sum += factor * freq[i].second;
        }

        return sum;
    }
};