class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;

        while(start <= n) {
            long long end = start * 1000 - 1;

            if(end > n) {
                end = n;
            }

            ans += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};