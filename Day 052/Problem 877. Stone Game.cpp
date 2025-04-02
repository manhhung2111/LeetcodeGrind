class Solution {
public:
    map<pair<int, int>, int> dp;
    int solve(int left, int right, const vector<int>& piles) {
        if (left > right) {
            return 0;
        }

        if (dp.find({left, right}) != dp.end()) {
            return dp[{left, right}];
        }
        
        bool aliceTurn = ((right - left + 1) & 1) == 0;
        int leftVal = aliceTurn ? piles[left] : 0;
        int rightVal = aliceTurn ? piles[right] : 0;

        if (aliceTurn) {
            return dp[{left, right}] = max(leftVal + solve(left + 1, right, piles), rightVal + solve(left, right - 1, piles));    
        }

        return dp[{left, right}] = min(leftVal + solve(left + 1, right, piles), rightVal + solve(left, right - 1, piles));
    }
    
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        for (int pile : piles) {
            sum += pile;
        }

        return solve(0, piles.size() - 1, piles) > sum / 2;
    }
};