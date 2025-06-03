#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] < heights[i]) {
                result[stk.top()]++;
                stk.pop();
            }

            if (!stk.empty()){
                result[stk.top()]++;
            }
            stk.push(i);
        }
        
        return result;
    }
};