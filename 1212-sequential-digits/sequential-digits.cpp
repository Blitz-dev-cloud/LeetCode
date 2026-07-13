class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for( int start = 1 ; start <= 9 ; start++ ) {
            int num = 0;

            for( int digit = start ; digit <= 9 ; digit++ ) {
                num = 10 * num + digit;

                if(num >= low && num<= high) {
                    result.push_back(num);
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};