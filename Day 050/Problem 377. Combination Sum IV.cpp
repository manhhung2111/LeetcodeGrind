class Solution {
public:
    unordered_map<int, int> dp;

    int solve(const vector<int> &nums, int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp.find(target) != dp.end()) return dp[target];

        int count = 0;
        for (int num : nums) {
            count += solve(nums, target - num);
        }

        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};