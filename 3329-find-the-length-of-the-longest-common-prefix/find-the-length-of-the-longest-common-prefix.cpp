class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();

        set<int> s;
        for( int a : arr2 ) {
            int temp = a;
            while(temp > 0) {
                s.insert(temp);
                temp /= 10;
            }
        }

        for( auto it = s.begin() ; it != s.end() ; it++ ) cout << *it << " ";
        
        int maxLen = 0;
        for( int a : arr1 ) {
            int temp = a;
            while(temp > 0) {
                if(s.find(temp) != s.end()) {
                    int len = 0, t = temp;
                    while(t > 0) {
                        len++;
                        t /= 10;
                    }
                    maxLen = max(maxLen, len);
                }
                temp /= 10;
            }
        }

        return maxLen;
    }
};