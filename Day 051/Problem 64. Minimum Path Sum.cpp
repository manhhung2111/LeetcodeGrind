class Solution {
public:
    int solve(int i, int j, const vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int minPath = min(solve(i, j + 1, grid, dp), solve(i + 1, j, grid, dp));
        return dp[i][j] = minPath == INT_MAX ? INT_MAX : minPath + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        
        return solve(0, 0, grid, dp);
    }
};