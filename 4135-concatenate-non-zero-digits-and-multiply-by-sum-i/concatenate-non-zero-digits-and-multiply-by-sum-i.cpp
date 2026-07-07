class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = "";
        long long sum = 0;
        while(n > 0) {
            int r = n % 10;
            if(r != 0) {
                s += r + '0';
                sum += r;
            }
            n /= 10;
        }
        reverse(s.begin(), s.end());
        int x = stoi(s);
        return x * sum;
    }
};