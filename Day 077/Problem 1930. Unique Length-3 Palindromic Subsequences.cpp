class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> occurrence;
        for (int i = 0; i < s.size(); i++) {
            occurrence[s[i]].push_back(i);
        }

        int result = 0;
        for (auto entry : occurrence) {
            if (entry.second.size() > 1) {
                unordered_set<char> uniqueChars;
                for (int i = entry.second.front() + 1; i < entry.second.back(); i++) {
                    uniqueChars.insert(s[i]);
                }

                result += uniqueChars.size();
            }
        }

        return result;
    }
};