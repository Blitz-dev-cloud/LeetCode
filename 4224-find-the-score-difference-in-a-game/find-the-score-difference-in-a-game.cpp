class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int pts1 = 0, pts2 = 0;
        int pts = 0;
        bool isSwapped = false;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            pts += nums[i];

            if((i + 1) % 6 == 0) isSwapped = !isSwapped;

            if(pts % 2 == 0) {
                 if(!isSwapped) pts1 += nums[i];
                 else pts2 += nums[i];
            } else {
                if(!isSwapped) pts2 += nums[i];
                else pts1 += nums[i];
            }
        }

        return pts1 - pts2;
    }
};