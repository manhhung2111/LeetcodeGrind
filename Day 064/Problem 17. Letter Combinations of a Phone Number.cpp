class Solution {
public:
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> result;
    void solve(int index, const string &digits, string &combination) {
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }

        for (char digit : mp[digits[index]]) {
            combination.push_back(digit);
            solve(index + 1, digits, combination);
            combination.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        string combination = "";
        solve(0, digits, combination);

        return result;
    }
};