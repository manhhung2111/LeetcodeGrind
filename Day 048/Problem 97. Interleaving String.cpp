class Solution {
public:

    map<pair<int, int>, bool> dp;
    bool solve(int i, int j, string s1, string s2, string s3) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }

        if (i < s1.size() && s1[i] == s3[i + j] && solve(i + 1, j, s1, s2, s3)) {
            return dp[{i, j}] = true;
        }

        if (j < s2.size() && s2[j] == s3[i + j] && solve(i, j + 1, s1, s2, s3)) {
            return dp[{i, j}] = true;
        }

        return dp[{i, j}] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        return solve(0, 0, s1, s2, s3);
    }
};