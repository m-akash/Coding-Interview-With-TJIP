/*
Complexity Analysis

Time Complexity: O(4^n)
Space Complexity: O(4^n)
*/
class Solution {
public:
    vector<string> result;
    const static unordered_map<char, string> digitToletter;
    void generateCombination(int pos, string& current_comb, const string& digits) {
        if (pos == digits.size()) {
            if (!current_comb.empty()) {
                result.push_back(current_comb);
            }
            return;
        }
        auto& letters = digitToletter.at(digits[pos]);
        for (auto& letter : letters) {
            current_comb.push_back(letter);
            generateCombination(pos + 1, current_comb, digits);
            current_comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        string current_comb = "";
        generateCombination(0, current_comb, digits);
        return result;
    }
};

const unordered_map<char, string> Solution::digitToletter = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};
