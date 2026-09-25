class Solution {
private:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> next = parseTerm();
            res.insert(next.begin(), next.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpression();
                pos++;
            } else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> temp;

            for (const string& a : res) {
                for (const string& b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};