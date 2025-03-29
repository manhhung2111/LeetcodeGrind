class Solution {
public:
    int solve(int row, int col, vector<vector<char>> &matrix, vector<vector<int>> &dp) {
        if (row >= matrix.size() || col >= matrix[0].size()) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        
        if (matrix[row][col] == '0') {
            return dp[row][col] = 0;
        }

        int topRight = solve(row, col + 1, matrix, dp);
        int bottomLeft = solve(row + 1, col, matrix, dp);
        int bottomRight = solve(row + 1, col + 1, matrix, dp);

        int edge = 1 + min(topRight, min(bottomLeft, bottomRight));
        return dp[row][col] = edge;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int>(m, -1));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (dp[i][j] == -1) {
                    solve(i, j, matrix, dp);
                }
            }
        }  

        int result = 0;
        for (vector<int> row : dp) {
            for (int edge : row) {
                result = max(result, edge * edge);
            }
        }

        return result;
    }
};