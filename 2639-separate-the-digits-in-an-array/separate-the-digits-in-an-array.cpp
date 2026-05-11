class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for( int num : nums ) {
            string str = to_string(num);
            for( char ch : str ) res.push_back(ch - '0');
        }
        return res;
    }
};