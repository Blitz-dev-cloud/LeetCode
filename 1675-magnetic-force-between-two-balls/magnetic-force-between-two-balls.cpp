class Solution {
private:
    bool canPlace(int gap, int m, vector<int> &positions) {
        int prevPos = positions[0];
        int ballsPlaced = 1;

        for( int i = 1 ; i < positions.size() ; i++ ) {
            int currPos = positions[i];

            if(currPos - prevPos >= gap) {
                prevPos = currPos;
                ballsPlaced++;
            }
        }

        return ballsPlaced >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());

        int l = 1;
        int r = (position[n - 1] - position[0]) / (m - 1.0);

        int ans = -1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canPlace(mid, m, position)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};