class Solution {
public:
    map<pair<int, int>, int> dp;
    int solve(int i, int j, string word1, string word2) {
        if (i == word1.size() && j == word2.size()) {
            return 0;
        } else if (i == word1.size()) {
            return word2.size() - j;
        } else if (j == word2.size()) {
            return word1.size() - i;
        }   

        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }

        if (word1[i] == word2[j]) {
            return dp[{i, j}] = solve(i + 1, j + 1, word1, word2);
        }

        int minCost = INT_MAX;
        // Insert a new character into word1
        minCost = min(1 + solve(i, j + 1, word1, word2), minCost);
        
        // Delete a character from word1
        minCost = min(1 + solve(i + 1, j, word1, word2), minCost);

        // Replace a character in word1
        minCost = min(1 + solve(i + 1, j + 1, word1, word2), minCost);

        return dp[{i, j}] = minCost;
    }
    
    int minDistance(string word1, string word2) {
        return solve(0, 0, word1, word2);
    }
};