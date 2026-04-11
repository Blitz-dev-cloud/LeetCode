class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> hm;

        for( int i = 0 ; i < n ; i++ ) {
            hm[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        for( auto& [key, value] : hm ) {
            if(value.size() >= 3) {
                for( int i = 0 ; i + 2 < value.size() ; i++ ) {
                    int dist = 2 * (value[i + 2] - value[i]);
                    minDist = min(minDist, dist);
                }
            }
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};