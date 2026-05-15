class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for( string str : chunks ) s += str;
        s += '\n';
        int n = s.size();
        
        unordered_map<string, int> freq;
        string temp = "";

        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ' || s[i] == '\n') { 
                if(!temp.empty() && temp[0] == '-') temp = temp.substr(1);
                if(!temp.empty() && temp[temp.size() - 1] == '-') temp.pop_back();

                if(!temp.empty()) freq[temp]++;
                cout << temp << endl;
                temp = "";
                while(i + 1 < n && s[i + 1] == ' ') i++;
            } else if(i < n - 1 && s[i] == '-' && s[i + 1] == '-') {
                if(!temp.empty() && temp[0] == '-') temp = temp.substr(1);
                if(!temp.empty() && temp[temp.size() - 1] == '-') temp.pop_back();

                if(!temp.empty()) freq[temp]++;
                cout << temp << endl;
                temp = "";
                i++;
            } 
            else temp += s[i];
        }

        int m = queries.size();
        vector<int> res(m, 0);
        int idx = 0;

        for( string q : queries ) {
            if(!freq.count(q)) {
                res[idx++] = 0;
            } else res[idx++] = freq[q];
        }

        return res;
    }
};