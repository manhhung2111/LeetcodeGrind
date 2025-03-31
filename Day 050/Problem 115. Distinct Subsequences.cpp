class Solution {
public:
    
    int solve(int i, int j, const string &s, const string &t, vector<vector<int>> &dp) {
        if (j == t.size()) {
            return 1;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] != t[j]) {
            return dp[i][j] = solve(i + 1, j, s, t, dp);
        }

        return dp[i][j] = solve(i + 1, j + 1, s, t, dp) + solve(i + 1, j, s, t, dp); 
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(0, 0, s, t, dp);
    }
};