class Solution {
public:

    map<pair<int, int>, int> dp;
    int solve(int left, int right, vector<int> piles) {
        if (left > right) {
            return 0;
        }

        if (dp.find({left, right}) != dp.end()) {
            return dp[{left, right}];
        }

        // Maximize alice's score
        bool aliceTurn = ((right - left + 1) & 1) == 0;

        if (aliceTurn) {
            return dp[{left, right}] = max(piles[left] + solve(left + 1, right, piles), piles[right] + solve(left, right - 1, piles));
        }

        // Bob's turn
        return dp[{left, right}] = min(solve(left + 1, right, piles), solve(left, right - 1, piles));
    }

    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for (int pile : piles) {
            total += pile;
        }

        return solve(0, piles.size() - 1, piles) > total / 2;
    }
};