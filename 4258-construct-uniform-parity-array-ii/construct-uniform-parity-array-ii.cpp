class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for( int x : nums1 ) {
            if(x % 2 != 0) minOdd = min(minOdd, x);
            else minEven = min(minEven, x);
        }

        bool flag = true;

        // Trying odd
        for( int x : nums1 ) {
            if(x != minOdd && x % 2 == 0) {
                if(x - minOdd < 1 || abs(x - minOdd) % 2 == 0) flag = false; 
            }
        }

        if(flag) return true;

        // Trying even
        for( int x : nums1 ) {
            if(x != minEven && x % 2 != 0) {
                if(x - minEven < 1 || abs(x - minEven) % 2 != 0) return false;
            }
        }

        return true;
    }
};