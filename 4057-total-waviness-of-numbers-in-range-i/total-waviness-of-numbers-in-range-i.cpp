class Solution {
private:
    int w(int x) {
        string s = to_string(x);
        int n = s.size();
        if(n < 3) return 0;

        int w = 0;
        for( int i = 1 ; i < n - 1 ; i++ ) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            int c = s[i + 1] - '0';
            if((b > c && b > a) || (b < c && b < a)) w++;
        }

        return w;
    }
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for( int i = num1 ; i <= num2 ; i++ ) {
            waviness += w(i);
        }
        return waviness;
    }
};