class Solution {
public:
    map<pair<int, int>, bool> dp;

    bool solve(int idx1, int idx2, string s1, string s2, string s3) {
        if (idx1 + idx2 == s3.size()) {
            return true;
        }

        if (dp.find({idx1, idx2}) != dp.end()) {
            return dp[{idx1, idx2}];
        }

        if (idx1 < s1.size() && s1[idx1] == s3[idx1 + idx2] && solve(idx1 + 1, idx2, s1, s2, s3)) {
            return dp[{idx1, idx2}] = true;
        }

        if (idx2 < s2.size() && s2[idx2] == s3[idx1 + idx2] && solve(idx1, idx2 + 1, s1, s2, s3)) {
            return dp[{idx1, idx2}] = true;
        }

        return dp[{idx1, idx2}] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return solve(0, 0, s1, s2, s3);
    }
};