class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if(memo.count(expression)) return memo[expression];

        vector<int> result;

        for( int i = 0 ; i < expression.size() ; i++ ) {
            char c = expression[i];

            if(c == '+' || c == '-' || c == '*') {
                auto left = diffWaysToCompute(expression.substr(0, i));
                auto right = diffWaysToCompute(expression.substr(i + 1));

                for( auto x : left ) {
                    for( auto y : right ) {
                        if(c == '+') result.push_back(x + y);
                        else if(c == '-') result.push_back(x - y);
                        else result.push_back(x * y);
                    }
                }
            }
        }

        if(result.empty()) result.push_back(stoi(expression));

        return memo[expression] = result;
    }
};