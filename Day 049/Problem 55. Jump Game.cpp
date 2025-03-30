class Solution {
public:
    unordered_map<int, bool> dp;
    bool solve(int index, vector<int> &nums) {
        if (index == nums.size() - 1) {
            return true;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        for (int i = 1; i <= nums[index]; i++) {
            if (solve(index + i, nums)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        return solve(0, nums);
    }
};