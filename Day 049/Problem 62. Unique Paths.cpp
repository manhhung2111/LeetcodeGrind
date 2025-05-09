class Solution {
public:
    int solve (int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int totalPath = 0;
        if (i + 1 < m) {
            totalPath += solve(i + 1, j, m, n, dp);
        }

        if (j + 1 < n) {
            totalPath += solve(i, j + 1, m, n, dp);
        }

        return dp[i][j] = totalPath;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};