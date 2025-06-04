class Solution {
public:

    vector<vector<int>> dp;
    int solve(int i, int j, const vector<vector<int>> &matrix) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int topRight = solve(i, j + 1, matrix);
        int botLeft = solve(i + 1, j, matrix);
        int botRight = solve(i + 1, j + 1, matrix);

        return dp[i][j] = 1 + min(topRight, min(botLeft, botRight));
    }
    
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int>(m, -1));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    result += solve(i, j, matrix);
                }
            }
        }

        return result;
    }
};