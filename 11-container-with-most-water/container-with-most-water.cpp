class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, marea = INT_MIN, area = 0;

        while( l <= r ) {
            area = min(height[l], height[r]) * (r - l);
            marea = max(marea, area);
            if(height[l] < height[r]) {
                l++;
            } else r--;
        }

        return marea;
    }
};