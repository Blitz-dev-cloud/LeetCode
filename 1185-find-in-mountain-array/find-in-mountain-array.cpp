/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), l, r, mid, peak = 0;
        l = 0;
        r = n - 1;
        while(l < r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) l = peak = mid + 1;
            else r = mid;
        }

        l = 0;
        r = peak;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) < target) l = mid + 1;
            else if(mountainArr.get(mid) > target) r = mid - 1;
            else return mid;
        }

        l = peak;
        r = n - 1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mountainArr.get(mid) > target) l = mid + 1;
            else if(mountainArr.get(mid) < target) r = mid - 1;
            else return mid;
        }

        return -1;
    }
};