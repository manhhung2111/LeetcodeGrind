class Solution {
public:
    vector<vector<int>> dp;
    int solve(int left, int right, const string &s) {
        if (left == right) {
            return 1;
        }

        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        
        if (s[left] == s[right]) {
            return dp[left][right] = 2 + solve(left + 1, right -1, s);
        }

        return dp[left][right] = max(solve(left + 1, right, s), solve(left, right -1, s));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};