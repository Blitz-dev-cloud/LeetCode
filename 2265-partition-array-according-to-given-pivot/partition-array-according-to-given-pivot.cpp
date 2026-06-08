class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smaller, larger;
        int pvtCnt = 0;

        for( int x : nums ) {
            if(x < pivot) smaller.push_back(x);
            else if(x == pivot) pvtCnt++;
            else if(x > pivot) larger.push_back(x);
        }

        while(pvtCnt-- > 0) smaller.push_back(pivot);

        for( int x : larger ) smaller.push_back(x);

        return smaller;
    }
};