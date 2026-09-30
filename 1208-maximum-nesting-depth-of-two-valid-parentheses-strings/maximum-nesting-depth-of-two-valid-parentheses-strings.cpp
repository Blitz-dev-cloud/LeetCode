class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans;

        // int bal = -1;
        bool oprevA = false;
        bool cprevA = false;

        for( char c : seq ) {
            if(c == '(') {
                if(!oprevA) {
                    ans.push_back(0);
                    oprevA = true;
                } else {
                    ans.push_back(1);
                    oprevA = false;
                }
            } else if(c == ')') {
                if(!cprevA) {
                    ans.push_back(0);
                    cprevA = true;
                } else {
                    ans.push_back(1);
                    cprevA = false;
                }
            }
        }

        return ans;
    }
};