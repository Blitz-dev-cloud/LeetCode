class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();

        unordered_map<string, string> kb;

        for( int j = 0 ; j < m ; j++ ) {
            string key = knowledge[j][0];
            string value = knowledge[j][1];

            kb[key] = value;
        }

        string ans = "";
        
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '(') {
                i++;
                string temp = "";
                temp += s[i++];
                while(s[i] != ')') {
                    temp += s[i++];
                }
                if(!kb.count(temp)) ans += '?';
                else {
                    ans += kb[temp];
                }
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};