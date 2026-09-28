class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> freq;
        // for( int x : nums1 ) freq[x]++;
        int n = nums1.size();
        // vector<int> ans;
        set<int> s;

        sort(nums1.begin(), nums1.end());

        for( int x : nums2 ) {
            int l = 0;
            int r = n - 1;

            int y = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(nums1[mid] == x) {
                    y = mid;
                    break;
                } else if(nums1[mid] < x) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(y != -1 && s.find(x) == s.end()) s.insert(x);
        }

        return vector<int> (s.begin(), s.end());
    }
};