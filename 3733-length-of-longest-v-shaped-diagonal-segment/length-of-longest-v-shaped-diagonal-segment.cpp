class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int directions[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};

        vector<vector<vector<vector<int>>>> memo(
            rows, vector<vector<vector<int>>>(
                cols, vector<vector<int>>(4, vector<int>(2, -1))
            )
        );

        function<int(int,int,int,bool,int)> dfs = [&](int r, int c, int dir, bool canTurn, int expectedVal) -> int {
            int nextR = r + directions[dir][0];
            int nextC = c + directions[dir][1];

            if(nextR < 0 || nextC < 0 || nextR >= rows || nextC >= cols || grid[nextR][nextC] != expectedVal)
                return 0;
            
            if(memo[nextR][nextC][dir][canTurn] != -1)
                return memo[nextR][nextC][dir][canTurn];
            
            int maxLength = dfs(nextR, nextC, dir, canTurn, 2 - expectedVal);

            if(canTurn) {
                int newDir = (dir + 1) % 4;
                maxLength = max(maxLength, dfs(nextR, nextC, newDir, false, 2 - expectedVal));
            }
            
            memo[nextR][nextC][dir][canTurn] = maxLength + 1;
            return memo[nextR][nextC][dir][canTurn];
        };
        
        int maxSegmentLength = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    for(int dir = 0; dir < 4; dir++){
                        maxSegmentLength = max(maxSegmentLength, dfs(r, c, dir, true, 2) + 1);
                    }
                }
            }
        }
        
        return maxSegmentLength;
    }
};