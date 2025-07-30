class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 0, h = n - 1;
        while(m <= h) {
            if(nums[m] == 0) {
                swap(nums[m], nums[l]);
                m++;
                l++;
            } else if(nums[m] == 1) {
                m++;
            } else{
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};