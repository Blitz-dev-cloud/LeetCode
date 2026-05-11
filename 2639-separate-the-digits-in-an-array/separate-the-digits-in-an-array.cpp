class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for( int num : nums ) {
            vector<int> temp;
            while(num > 0) {
                int r = num % 10;
                temp.push_back(r);
                num /= 10;
            }
            reverse(temp.begin(), temp.end());
            for( int n : temp ) res.push_back(n);
        }
        return res;
    }
};