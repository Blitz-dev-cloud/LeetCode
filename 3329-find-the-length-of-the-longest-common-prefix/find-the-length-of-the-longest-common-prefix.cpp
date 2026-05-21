class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();

        /*set<int> s;
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
        }*/

        unordered_map<int, int> freq1, freq2;

        for( int a : arr1 ) {
            int temp = a;
            while(temp > 0) {
                int t = temp, l = 0;
                while(t > 0) {
                    l++;
                    t /= 10;
                }
                if(!freq1.count(temp)) freq1[temp] = l;
                temp /= 10;
            }
        }

        for( int a : arr2 ) {
            int temp = a;
            while(temp > 0) {
                int t = temp, l = 0;
                while(t > 0) {
                    l++;
                    t /= 10;
                }
                if(!freq2.count(temp)) freq2[temp] = l;
                temp /= 10;
            }
        }
        
        int maxLen = 0;

        for( auto& m : freq1 ) {
            auto [key, value] = m;
            if(freq2.count(key)) maxLen = max(maxLen, value);
        }

        return maxLen;
    }
};