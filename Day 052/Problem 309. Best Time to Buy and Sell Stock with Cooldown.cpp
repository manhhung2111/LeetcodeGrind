class Solution {
public:
    map<pair<int, bool>, int> dp;
    int solve(int index, bool buying, const vector<int> &prices) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp.find({index, buying}) != dp.end()) {
            return dp[{index, buying}];
        }

        if (buying) {
            int buy = solve(index + 1, !buying, prices) - prices[index];
            int cooldown = solve(index + 1, buying, prices);

            return dp[{index, buying}] = max(buy, cooldown);
        }

        int sell = solve(index + 2, !buying, prices) + prices[index];
        int cooldown = solve(index + 1, buying, prices);

        return dp[{index, buying}] = max(sell, cooldown);
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, true, prices);
    }
};