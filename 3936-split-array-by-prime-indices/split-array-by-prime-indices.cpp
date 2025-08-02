class Solution {
private:
    bool isPrime(int n) {
        if(n == 0 || n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for( int i = 3 ; i * i <= n ; i += 2 ) {
            if(n % i == 0) return false;
        }

        return true;
    }
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeArr, restArr;
        for( int i = 0 ; i < n ; i++ ) {
            if(isPrime(i)) primeArr.push_back(nums[i]);
            else restArr.push_back(nums[i]);
        }

        long long a = 0, b = 0;

        for( int i = 0 ; i<  primeArr.size() ; i++ ) {
            a += primeArr[i];
        }
        for( int i = 0 ; i < restArr.size() ; i++ ) {
            b += restArr[i];
        }
        
        return abs(a - b);
    }
};