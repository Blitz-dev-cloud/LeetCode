class Solution {
public:
    int maximum69Number (int num) {
        /*vector<int> arr;
        while(num > 0) {
            int r = num % 10;
            arr.push_back(r);
            num /= 10;
        }
        for( int i = arr.size() - 1 ; i >= 0 ; i-- ) {
            if(arr[i] == 6) {
                arr[i] = 9;
                break;
            }
        }
        int n = 0;
        for( int i = 0 ; i < arr.size() ; i++ ) {
            n += arr[i] * pow(10, i);
        }
        return n;*/
        int n = num, pos = 1, change = 0;
        while( n > 0 ) {
            if(n % 10 == 6) change = 3 * pos;
            n /= 10;
            pos *= 10;
        }
        return num + change;
    }
};