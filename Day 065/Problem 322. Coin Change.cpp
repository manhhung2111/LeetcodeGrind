class Solution {
public:
    map<pair<int, int>, int> dp;
    int solve(int index, int amount, const vector<int>& coins) {
        if (amount == 0) {
            return 0;
        }

        if (index >= coins.size() || amount < 0) {
            return INT_MAX - 1;
        }

        if (dp.find({index, amount}) != dp.end()) {
            return dp[{index, amount}];
        }

        int take = 1 + solve(index, amount - coins[index], coins);
        int skip = solve(index + 1, amount, coins);

        return dp[{index, amount}] = min(take, skip);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int result = solve(0, amount, coins);
        if (result == INT_MAX - 1) return -1;
        return result;
    }
};