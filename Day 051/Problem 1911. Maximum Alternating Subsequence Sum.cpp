class Solution {
public:

    long long solve(int index, int col, const vector<int> &nums, vector<vector<long long>> &dp) {
        if (index >= nums.size()) {
            return 0; 
        }

        if (dp[index][col] != -1) {
            return dp[index][col];
        }

        int sign = col == 0 ? 1 : -1;
        long long take = nums[index] * sign + solve(index + 1, 1 - col, nums, dp);
        long long skip = solve(index + 1, col, nums, dp);

        return dp[index][col] = max(take, skip);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(0, 0, nums, dp);
    }
};