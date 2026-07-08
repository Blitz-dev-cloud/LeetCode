class Solution {
private:
    bool canShip(vector<int> &weights, int days, int cap) {
        int requiredDays = 1;
        int load = 0;

        for( int weight : weights ) {
            if(load + weight > cap) {
                requiredDays++;
                load = weight;
            } else {
                load += weight;
            }
        }

        return requiredDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(canShip(weights, days, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};