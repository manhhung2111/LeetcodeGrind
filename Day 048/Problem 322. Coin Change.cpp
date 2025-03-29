class Solution {
public:
    map<pair<int, int>, int> dp;
    
    int solve(int index, vector<int>& coins, int target) {
        if (target == 0) return 0;
        if (target < 0 || index >= coins.size()) return INT_MAX - 1;
        
        if (dp.find({index, target}) != dp.end()) {
            return dp[{index, target}];
        }

        int take = 1 + solve(index, coins, target - coins[index]);
        int skip = solve(index + 1, coins, target);

        return dp[{index, target}] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int result = solve(0, coins, amount);
        return result == INT_MAX - 1 ? -1 : result;
    }
};
