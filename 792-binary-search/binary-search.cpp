class Solution {
public:
    int binary_search(vector<int> &nums, int l, int h, int target){
        if(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                l = mid + 1;
            } else{
                h = mid - 1;
            }
            return binary_search(nums, l, h, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};