class Solution {
private:
    bool canEat(vector<int> &piles, int h, int k) {
        int hours = 0;
        for( int pile : piles ) {
            hours += pile / k;
            if(pile % k != 0) hours++;
            if(hours > h) return false;
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int result = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canEat(piles, h, mid)) {
                result = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return result;
    }
};