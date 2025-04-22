class Solution {
public:
    
    vector<string> result;
    void solve(int index, const string &s, string &combination, const unordered_set<string> &dict) {
        if (index == s.size()) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string str = s.substr(index, i - index + 1);
            if (dict.find(str) != dict.end()) {
                if (combination.size() == 0) combination += str;
                else {
                    combination += " " + str;
                }

                solve(i + 1, s, combination, dict);

                for (int c : str) {
                    combination.pop_back();
                }

                if (combination.size() != 0) combination.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string combination = "";
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        solve(0, s, combination, dict);

        return result;
    }
};