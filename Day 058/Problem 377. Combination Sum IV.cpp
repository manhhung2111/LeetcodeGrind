class Solution {
public:
    unordered_map<int, int> dp;
    int solve(const vector<int>& nums, int remaining) {
        if (remaining == 0) {
            return 1;
        }

        if (remaining < 0) {
            return 0;
        }

        if (dp.find(remaining) != dp.end()) {
            return dp[remaining];
        }

        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += solve(nums, remaining - nums[i]);
        }

        return dp[remaining] = total;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};