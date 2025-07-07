class Solution {
public:
    int possibleStringCount(string word) {
        stack<pair<char, int>> stk;

        for (char c : word) {
            if (!stk.empty() && stk.top().first == c) {
                pair<char, int> top = stk.top();
                top.second++;
                stk.pop();
                stk.push(top);
            } else {
                stk.push({c, 1});
            }
        }

        int distinctChars = 0;
        int total = 0;

        while (!stk.empty()) {
            if (stk.top().second != 1) {
                distinctChars++;
                total += stk.top().second;
            }
            stk.pop();
        }

        return total - (distinctChars - 1);
    }
};