class Solution {
public:

    int solve(int row, int col, const vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (row >= matrix.size() || col >= matrix[0].size()) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int maxPath = 1;
        if (row > 0 && matrix[row][col] < matrix[row - 1][col]) {
            maxPath = max(maxPath, 1 + solve(row - 1, col, matrix, dp));
        } 

        if (col < matrix[0].size() - 1 && matrix[row][col] < matrix[row][col + 1]) {
            maxPath = max(maxPath, 1 + solve(row, col + 1, matrix, dp));
        }

        if (row < matrix.size() - 1 && matrix[row][col] < matrix[row + 1][col]) {
            maxPath = max(maxPath, 1 + solve(row + 1, col, matrix, dp));
        }

        if (col > 0 && matrix[row][col] < matrix[row][col - 1]) {
            maxPath = max(maxPath, 1 + solve(row, col - 1, matrix, dp));
        }

        return dp[row][col] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1) {
                    solve(i, j, matrix, dp);
                }
            }
        }

        int result = 1;
        for (vector<int> row : dp) {
            for (int val : row) {
                result = max(val, result);
            }
        }

        return result;
    }
};