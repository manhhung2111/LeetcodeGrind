class Solution {
public:
    
    map<pair<int, int>, int> dp;
    int solve(int index, int amount, const vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }

        if (index >= coins.size() || amount < 0) {
            return 0;
        }

        if (dp.find({index, amount}) != dp.end()) {
            return dp[{index, amount}];
        }

        int take = solve(index, amount - coins[index], coins);
        int skip = solve(index + 1, amount, coins);

        return dp[{index, amount}] = take + skip;
    }
    
    
    int change(int amount, vector<int>& coins) {
        return solve(0, amount, coins);
    }
};