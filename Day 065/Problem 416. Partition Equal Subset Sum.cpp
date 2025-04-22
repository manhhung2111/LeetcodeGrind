class Solution {
public:

    map<pair<int, int>, int> dp;
    bool solve(int index, int amount, const vector<int> &nums) {
        if (amount == 0) {
            return true;
        }

        if (index >= nums.size() || amount < 0) {
            return false;
        }

        if (dp.find({index, amount}) != dp.end()) {
            return dp[{index, amount}];
        }

        return dp[{index, amount}] = solve(index + 1, amount - nums[index], nums) || solve(index + 1, amount, nums);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum & 1) return false;
        return solve(0, sum / 2, nums);
    }
};