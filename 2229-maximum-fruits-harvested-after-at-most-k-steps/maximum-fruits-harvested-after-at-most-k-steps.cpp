class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> positions, prefix(n + 1, 0);

        for( int i = 0 ; i < n ; i++ ) {
            positions.push_back(fruits[i][0]);
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        int count = 0;

        for( int i = 0, j = 0 ; i < n ; i++) {
            while(j < n) {
                int left = fruits[i][0], right = fruits[j][0];
                int goLeftThenRight = abs(startPos - left) + (right - left);
                int goRightThenLeft = abs(startPos - right) + (right - left);

                if(min(goLeftThenRight, goRightThenLeft) > k) break;
                ++j;
            }
            count = max(count, prefix[j] - prefix[i]);
        }
        return count;
    }
};