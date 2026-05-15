class Solution {
private:
    int search(vector<int> &nums, int l, int r) {
        if(nums[l] <= nums[r]) return nums[l];
        if(l <= r) {
            int mid = l + (r - l) / 2;
            if(mid < r && nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if(mid > l && nums[mid] < nums[mid - 1]) return nums[mid];
            else if(nums[r] > nums[mid]) return search(nums, l, mid - 1);
            else if(nums[r] < nums[mid]) return search(nums, mid + 1, r);
        }
        return -1;
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return search(nums, 0, n - 1);
    }
};