class Solution {
public:
    // Try to find the maximum value Alice can take
    vector<vector<int>> dp;
    int solve(int index, bool aliceTurn, const vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (index >= n) {
            return 0;
        }

        if (dp[index][aliceTurn] != -1) {
            return dp[index][aliceTurn];
        }

        if (aliceTurn) {
            int score = stoneValue[index] + solve(index + 1, false, stoneValue);
            if (index + 1 < n) {
                score = max(score, stoneValue[index] + stoneValue[index + 1] + solve(index + 2, false, stoneValue));
            }

            if (index + 2 < n) {
                score = max(score, stoneValue[index] + stoneValue[index + 1] + stoneValue[index + 2] + solve(index + 3, false, stoneValue));
            }

            return dp[index][aliceTurn] = score;
        }

        // Bob's turn
        int score = solve(index + 1, true, stoneValue);
        if (index + 1 < n) {
            score = min(score, solve(index + 2, true, stoneValue));
        }

        if (index + 2 < n) {
            score = min(score, solve(index + 3, true, stoneValue));
        }

        return dp[index][aliceTurn] = score;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int total = 0;
        for (int weight : stoneValue) {
            total += weight;
        }
        
        dp.assign(stoneValue.size(), vector<int>(2, -1));
        int aliceScore = solve(0, true, stoneValue);
        int bobScore = total - aliceScore;

        if (aliceScore == bobScore) {
            return "Tie";
        }
        if (aliceScore > bobScore) {
            return "Alice";
        }

        return "Bob";
    }
};