class Solution {
public:

    unordered_map<int, int> dp;
    int solve(int remaining, const vector<int> &nums) {
        if (remaining == 0) {
            return 1;
        }
        
        if (remaining < 0) {
            return 0;
        }

        if (dp.find(remaining) != dp.end()) {
            return dp[remaining];
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += solve(remaining - nums[i], nums);
        }

        return dp[remaining] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solve(target, nums);
    }
};