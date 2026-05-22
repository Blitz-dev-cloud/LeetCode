class Solution {
private:
    int searchTarget(int l, int r, vector<int> &nums, int target) {
        if(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target <= nums[mid]) return searchTarget(l, mid - 1, nums, target);
                else return searchTarget(mid + 1, r, nums, target);
            }
            else if(nums[mid] <= nums[r]) {
                if(nums[mid] <= target && target <= nums[r]) return searchTarget(mid + 1, r, nums, target);
                else return searchTarget(l, mid - 1, nums, target);
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return searchTarget(0, n - 1, nums, target);
    }
};