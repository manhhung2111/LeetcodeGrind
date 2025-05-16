class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);


        int endIndex = 0;
        int maxLen = 1;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (hammingDistance(words[i], words[j]) && groups[i] != groups[j] && dp[i] < dp[j] + 1) {
                    prev[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }

            if (dp[i] > maxLen) {
                endIndex = i;
                maxLen = dp[i];
            }
        }

        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = prev[endIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool hammingDistance(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) return false;
        
        int diffChars = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diffChars++;

            if (diffChars > 1) return false;
        }

        return true;
    }
};