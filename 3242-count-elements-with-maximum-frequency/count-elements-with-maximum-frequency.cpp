class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = 0;
        for (auto& [num, count] : freq) {
            if (count > maxFreq) maxFreq = count;
        }

        int total = 0;
        for (auto& [num, count] : freq) {
            if (count == maxFreq) total += count;
        }

        return total;
    }
};