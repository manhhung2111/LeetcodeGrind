class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;

        int i = 0, j = 0;
        while (i < pushed.size() && j < popped.size()) {
            if (stk.empty()) {
                stk.push(pushed[i++]);
            }

            if (!stk.empty()) {
                if (stk.top() == popped[j]) {
                    stk.pop();
                    j++;
                } else {
                    stk.push(pushed[i++]);
                }
            }
        }

        while (j < popped.size()) {
            if (stk.empty() || stk.top() != popped[j]) return false;
            stk.pop();
            j++;
        }

        return stk.empty();
    }
};