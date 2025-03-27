class Solution {
public:
    map<pair<int, int>, int> dp;

    int solve(int index, int total, vector<int> &nums, int target) {
        if (index == nums.size()) {
            if (total == target) return 1;
            return 0;
        }

        if (dp.find({index, total}) != dp.end()) {
            return dp[{index, total}];
        }

        dp[{index, total}] = solve(index + 1, total + nums[index], nums, target) + 
                            solve(index + 1, total - nums[index], nums, target);

        return dp[{index, total}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        return solve(0, total, nums, target);
    }
};