class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int pts1 = 0, pts2 = 0;
        int pts = 0;
        bool isSwapped = false;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            pts += nums[i];

            if((i + 1) % 6 == 0) isSwapped = !isSwapped;

            bool isEven = (pts % 2 == 0);

            if(isEven ^ isSwapped) pts1 += nums[i];
            else pts2 += nums[i];
        }

        return pts1 - pts2;
    }
};