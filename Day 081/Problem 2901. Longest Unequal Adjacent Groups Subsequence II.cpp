class Solution {
public:

    bool isValid(const string &word1, const string &word2) {
        if (word1.size() != word2.size()) return false;
        int diffChars = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) diffChars++;
            if (diffChars > 1) return false;
        }

        return diffChars == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);

        vector<int> parent(n, -1);
        int index = n - 1;
        int longestLen = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (isValid(words[i], words[j]) && groups[i] != groups[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > longestLen) {
                index = i;
                longestLen = dp[i];
            }
        }
        
        vector<string> result;
        while (index != -1) {
            result.push_back(words[index]);
            index = parent[index];
        }

        return result;
    }
};