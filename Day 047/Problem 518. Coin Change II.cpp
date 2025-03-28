class Solution {
public:

    map<pair<int, int>, int> dp;
    int solve(int index, vector<int> &coins, int target) {
        if (target == 0) {
            return 1;
        }

        if (target < 0 || index >= coins.size()) {
            return 0;
        }

        if (dp.find({index, target}) != dp.end()) {
            return dp[{index, target}];
        }

        dp[{index, target}] = solve(index, coins, target - coins[index]) + solve(index + 1, coins, target);
        return dp[{index, target}];
    }

    int change(int amount, vector<int>& coins) {
        return solve(0, coins, amount);
    }
};