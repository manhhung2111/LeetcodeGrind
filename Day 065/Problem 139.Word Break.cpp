class Solution {
public:
    unordered_map<int, bool> dp;
    bool solve(int index, const string &s, const unordered_map<string, bool> &dict) {
        if (index == s.size()) {
            return true;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        for (int i = index; i < s.size(); i++) {
            string str = s.substr(index, i - index + 1);
            if (dict.find(str) != dict.end()) {
                if (solve(i + 1, s, dict)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for (string word : wordDict) {
            dict[word] = true;
        }

        return solve(0, s, dict);
    }
};