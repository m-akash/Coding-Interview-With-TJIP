

class Solution {
public:
    void generateParenthesis_helper(int opening, int closing, int n, string& current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (opening > 0) {
            current.push_back('(');
            generateParenthesis_helper(opening - 1, closing, n, current, result);
            current.pop_back();
        }
        if (opening < closing) {
            current.push_back(')');
            generateParenthesis_helper(opening, closing - 1, n, current, result);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> result;
        generateParenthesis_helper(n, n, n, current, result);
        return result;
    }
};
