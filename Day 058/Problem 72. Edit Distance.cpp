class Solution {
public:

    map<pair<int, int>, int> dp;
    int solve(int idx1, int idx2, string word1, string word2) {
        if (idx1 == word1.size() && idx2 == word2.size()) {
            return 0;
        }

        if (idx1 == word1.size()) {
            return word2.size() - idx2;
        }

        if (idx2 == word2.size()) {
            return word1.size() - idx1;
        } 
        
        if (dp.find({idx1, idx2}) != dp.end()) {
            return dp[{idx1, idx2}];
        }

        if (word1[idx1] == word2[idx2]) {
            return dp[{idx1, idx2}] = solve(idx1 + 1, idx2 + 1, word1, word2);
        }

        int moves = 1 + solve(idx1, idx2 + 1, word1, word2);
        moves = min(moves, 1 + solve(idx1 + 1, idx2, word1, word2));
        moves = min(moves, 1 + solve(idx1 + 1, idx2 + 1, word1, word2));

        return dp[{idx1, idx2}] = moves;
    }

    int minDistance(string word1, string word2) {
        return solve(0, 0, word1, word2);
    }
};