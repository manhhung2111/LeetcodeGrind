class Solution {
public:
    vector<vector<int>> dp;
    int solve(int index, bool buying, const vector<int> &prices) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][buying] != -1) {
            return dp[index][buying];
        }

        if (buying) {
            int profit = -prices[index] + solve(index + 1, !buying, prices);
            profit = max(profit, solve(index + 1, buying, prices));

            return dp[index][buying] = profit;
        }

        int profit = prices[index] + solve(index + 2, !buying, prices);
        profit = max(profit, solve(index + 1, buying, prices));

        return dp[index][buying] = profit;
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return solve(0, true, prices);
    }
};