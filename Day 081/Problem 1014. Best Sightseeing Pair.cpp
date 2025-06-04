class Solution {
public:

    int solve(int index, bool isSecondSight, const vector<int> &values, vector<vector<int>> &dp) {
        if (index >= values.size()) return INT_MIN;

        if (dp[index][isSecondSight] != -1) {
            return dp[index][isSecondSight];
        }

        if (isSecondSight) {
            int take = values[index] - index;
            int skip = solve(index + 1, isSecondSight, values, dp);

            return dp[index][isSecondSight] = max(take, skip);
        }

        int take = values[index] + index + solve(index + 1, !isSecondSight, values, dp);
        int skip = solve(index + 1, isSecondSight, values, dp);

        return dp[index][isSecondSight] = max(take, skip);
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();  
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, false, values, dp);
    }
};