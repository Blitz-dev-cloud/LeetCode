class Solution {
public:
    //blitz
    int f(int l, int r, vector<int> &nums, int target){
        if(l == r){
            if(nums[l] == target) return l;
            return -1;
        }
        int mid = (l + r) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return f(mid + 1, r, nums, target);
        else return f(l, mid, nums, target);
    }
    int search(vector<int>& nums, int target) {
        return f(0, nums.size() - 1, nums, target);
    }
};