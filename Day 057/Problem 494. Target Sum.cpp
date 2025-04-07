class Solution {
public:
    map<pair<int, int>, int> dp;
    int solve(int index, int remaining, vector<int>& nums) {
        if (index == nums.size()) {
            if (remaining == 0)
                return 1;
            return 0;
        }

        if (dp.find({index, remaining}) != dp.end()) {
            return dp[{index, remaining}];
        }

        return dp[{index, remaining}] =
                   solve(index + 1, remaining - nums[index], nums) +
                   solve(index + 1, remaining + nums[index], nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};