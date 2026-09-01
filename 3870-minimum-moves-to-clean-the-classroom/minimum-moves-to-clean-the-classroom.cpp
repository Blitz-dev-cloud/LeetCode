class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int lcnt = 0;
        int sx = -1, sy = -1;

        int n = classroom.size();
        int m = classroom[0].size();

        vector<vector<int>> id(n, vector<int> (m, -1));

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if(classroom[i][j] == 'L') {
                    id[i][j] = lcnt;
                    lcnt++;
                }
            }
        }

        vector<vector<vector<int>>> bestEnergy(n, vector<vector<int>> (m, vector<int> (1 << lcnt, INT_MIN)));
        bestEnergy[sx][sy][0] = energy;

        queue<vector<int>> q;
        q.push({sx, sy, energy, 0, 0});

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        int fullMask = (1 << lcnt) - 1;

        while(!q.empty()) {
            auto a = q.front();
            q.pop();

            int x = a[0];
            int y = a[1];
            int e = a[2];
            int mask = a[3];
            int steps = a[4];

            if(mask == fullMask) return steps;

            if(e == 0) continue;

            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && classroom[nx][ny] != 'X') {
                    int nextMask = mask;
                    int nextEnergy = e - 1;

                    if(classroom[nx][ny] == 'L') {
                        nextMask |= (1 << id[nx][ny]);
                    }

                    if(classroom[nx][ny] == 'R') {
                        nextEnergy = energy;
                    }

                    if(bestEnergy[nx][ny][nextMask] >= nextEnergy) continue;

                    bestEnergy[nx][ny][nextMask] = nextEnergy;

                    q.push({nx, ny, nextEnergy, nextMask, steps + 1});
                }
            }
        }

        return -1;
    }
};