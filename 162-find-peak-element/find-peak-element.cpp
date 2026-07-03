class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // if(n == 1) return 0;

        int l = 0 , r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if((mid - 1 < 0 || nums[mid] > nums[mid - 1]) && (mid + 1 == n || nums[mid] > nums[mid + 1])) return mid;
            else if(mid != 0 && nums[mid] < nums[mid - 1]) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};