class Solution {
public:
    vector<string> result;

    void solve(int index, string &path, const string& s, const unordered_set<string>& dict) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string str = s.substr(index, i - index + 1);
            if (dict.find(str) != dict.end()) {
                path += (path.empty() ? "" : " ") + str;
                solve(i + 1, path, s, dict);

                for (char c : str) {
                    path.pop_back();
                }
                if (!path.empty()) {
                    path.pop_back();
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string path = "";
        solve(0, path, s, dict);
        return result;
    }
};
