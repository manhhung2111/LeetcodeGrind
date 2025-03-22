class Solution {
public:
    vector<string> result;
    map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    void dfs(int index, string &digits, string &combination) {
        if (combination.size() == digits.size()) {
            result.push_back(combination);
            return;
        }

        for (int i = 0; i < mp[digits[index]].size(); i++) {
            combination.push_back(mp[digits[index]][i]);
            dfs(index + 1, digits, combination);
            combination.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string combination = "";
        dfs(0, digits, combination);

        return result;
    }
};