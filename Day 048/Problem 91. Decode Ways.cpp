class Solution {
public:
    bool isValid(string s) {
        if (s.size() > 2 || s.size() < 1) return false;
        if (s[0] == '0') return false;

        int value = stoi(s);
        return value >= 1 && value <= 26;
    }
    
    map<int, int> dp;
    int solve(int index, string s) {
        if (index == s.size()) {
            return 1;
        }

        if (dp.find(index) != dp.end()) {
            return dp[index];
        }

        int count = 0;
        for (int i = index; i < s.size(); i++) {
            string sub = s.substr(index, i - index + 1);
            if (isValid(sub)) {
                count += solve(i + 1, s);
            }
        }

        dp[index] = count;
        return dp[index];
    }

    int numDecodings(string s) {
        return solve(0, s);
    }
};