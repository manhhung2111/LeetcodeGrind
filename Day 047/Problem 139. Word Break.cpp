class Solution {
public:

    map<int, bool> dp;
    bool solve(int index,const string &s, const unordered_set<string> &dict) {
        if (index == s.size()) {
            return true;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        for (int i = index; i < s.size(); i++) {
            string substr = s.substr(index, i - index + 1);
            if (dict.find(substr) != dict.end()) {
                if (solve(i + 1, s, dict)) {
                    dp[index] = true;
                    return true;
                }
            }
        }

        dp[index] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string word : wordDict) {
            dict.insert(word);
        }
        
        return solve(0, s, dict);
    }
};