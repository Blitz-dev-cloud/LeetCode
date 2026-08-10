class Solution {
private:
    bool canShip(int cap, int days, vector<int> &weights) {
        int curr = 0;
        int used = 1;
        for( int w : weights ) {
            if(curr + w <= cap) {
                curr += w;
            } else {
                used++;
                curr = w;
            }
        }
        return used <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int ans = 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canShip(mid, days, weights)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};