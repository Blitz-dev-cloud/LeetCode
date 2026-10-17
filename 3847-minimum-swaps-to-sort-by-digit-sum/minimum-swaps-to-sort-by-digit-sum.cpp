class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
            int s1 = digitSum(a.first);
            int s2 = digitSum(b.first);

            if (s1 != s2) return s1 < s2;
            return a.first < b.first;
        });

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (pos[i] != i) {
                int j = pos[i];

                swap(pos[i], pos[j]);
                swaps++;
            }
        }

        return swaps;
    }
};