class Solution {
public:
    unordered_map<int, int> dp;
    int solve(int index, vector<int> &nums) {
        if (index >= nums.size() - 1) {
            return 0;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        int minJump = INT_MAX - 1;
        for (int i = 1; i <= nums[index]; i++) {
            minJump = min(minJump, 1 + solve(index + i, nums));
        }

        return dp[index] = minJump;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};