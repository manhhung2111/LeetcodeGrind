class Solution {
public:

    vector<vector<vector<int>>> dp;
    int solve(int index, bool buying, int k, const vector<int>& prices) {
        if (index >= prices.size() || k <= 0) {
            return 0;
        }

        if (dp[index][buying][k] != -1) {
            return dp[index][buying][k];
        }

        if (buying) {
            int buy = -prices[index] + solve(index + 1, !buying, k, prices);
            int skip = solve(index + 1, buying, k, prices);

            return dp[index][buying][k] = max(buy, skip);
        }

        int sell = prices[index] + solve(index + 1, !buying, k - 1, prices);
        int skip = solve(index + 1, buying, k, prices);

        return dp[index][buying][k] = max(sell, skip);
    }

    int maxProfit(int k, vector<int>& prices) {
        dp.resize(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, true, k, prices);
    }
};