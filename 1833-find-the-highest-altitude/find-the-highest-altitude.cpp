class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxEl = INT_MIN, el = 0;

        for( int x : gain ) {
            el += x;
            maxEl = max(maxEl, el);
        }

        return maxEl > 0 ? maxEl : 0;
    }
};