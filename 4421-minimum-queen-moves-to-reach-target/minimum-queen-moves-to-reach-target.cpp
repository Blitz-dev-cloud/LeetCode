class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source == target) return 0;
        
        int x1 = source[0];
        int y1 = source[1];
        int x2 = target[0];
        int y2 = target[1];

        if(x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) return 1;
        else return 2;
    }
};