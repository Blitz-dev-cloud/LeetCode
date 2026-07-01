class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int area = 0, maxArea = INT_MIN;

        while(l < r) {
            area = (r - l) * min(height[l], height[r]);
            maxArea = max(maxArea, area);
            if(height[l] < height[r]) l++;
            else r--;
        }

        return maxArea;
    }
};