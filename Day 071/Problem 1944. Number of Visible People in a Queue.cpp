class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> stk;
        vector<int> result(n, 0);

        for (int i = 0; i < heights.size(); i++) {
            int itemPop = 1;
            while (!stk.empty() && heights[i] > heights[stk.top()]) {
                result[stk.top()]++;
                stk.pop();
            }

            if (!stk.empty()) {
                result[stk.top()]++;
            }

            stk.push(i);
        }

        return result;
    }
};