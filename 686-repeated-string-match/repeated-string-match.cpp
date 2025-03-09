class Solution {
public:
    //blitz
    int rabin_karp(string a, string b, int q){
        int m = a.length(), n = b.length();
        int i, j;
        long long t = 0, p = 0, h = 1, d = 256;

        for( int i = 0 ; i < n - 1 ; i++ ){
            h = (h * d) % q;
        }

        for( int i = 0 ; i < n ; i++ ){
            t = (d * t + a[i]) % q;
            p = (d * p + b[i]) % q;
        }

        vector<int> res;

        for( int i = 0 ; i <= m - n ; i++ ){
            if(t == p && a.substr(i, n) == b){
                return 1;
            }
            if(i < m - n){
                t = (d * (t - a[i] * h) + a[i + n]) % q;
                if(t < 0){
                    t += q;
                }
            }
        }

        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b){
            return 1;
        }
        int q = 1e9 + 7, count = 1;
        string str = a;
        int m = a.length(), n = b.length();
        while(str.length() < n){
            str += a;
            count++;
        }
        if(str == b){
            return count;
        }
        if(rabin_karp(str, b, q) != -1){
            return count;
        }
        if(rabin_karp(str + a, b, q) != -1){
            return count + 1;
        }
        return -1;
    }
};