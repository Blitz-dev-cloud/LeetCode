class Solution {
private:
    bool canFinish(long long minTime, vector<int> &time, int totalTrips) {
        long long trips = 0;
        for( int t : time ) {
            trips += minTime / (1LL* t);
            if(trips >= (1LL * totalTrips)) return true;
        }

        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        sort(time.begin(), time.end());

        long long l = 1;
        long long r = 1LL * totalTrips * *max_element(time.begin(), time.end());

        long long ans = 0;

        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(canFinish(mid, time, totalTrips)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};