class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        map<int, int> freq;
        for( int x : nums ) freq[x]++;

        map<int, int> freqCnt;
        for( auto &it : freq ) {
            freqCnt[it.second]++;
        }

        for( auto x : nums ) {
            if(freqCnt[freq[x]] == 1) return x; 
        }

        return -1;
    }
};