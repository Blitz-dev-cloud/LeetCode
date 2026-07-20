class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (abs(start[0] - target[0]) + abs(start[1] - target[1])) % 2 == 0;
    }
};