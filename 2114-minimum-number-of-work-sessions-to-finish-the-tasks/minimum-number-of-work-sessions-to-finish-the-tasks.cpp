class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();

        vector<pair<int, int>> dp(1 << n, {INT_MAX, 0});
        dp[0] = {1, 0};

        for( int mask = 1 ; mask < (1 << n) ; mask++ ) {
            for( int i = 0 ; i < n ; i++ ) {
                if(mask & (1 << i)) {
                    int prevMask = mask ^ (1 << i);

                    auto [sessionsCnt, usedTime] = dp[prevMask];

                    int time = tasks[i];
                    // int timeRemaining = sessionTime - usedTime;

                    /*if(timeRemaining > time) {
                        timeRemaining -= time;
                        time = 0;
                    } else if(time == timeRemaining) {
                        time = 0;
                        timeRemaining = 0;
                    } else {
                        sessionsCnt++;
                        timeRemaining = sessionTime - time % sessionTime;
                    }

                    usedTime = sessionTime - timeRemaining;*/

                    if(usedTime + time <= sessionTime) {
                        usedTime += time;
                    } else {
                        sessionsCnt++;
                        usedTime = time;
                    }

                    dp[mask] = min(dp[mask], {sessionsCnt, usedTime});
                }
            }
        }

        return dp[(1 << n) - 1].first;
    }
};