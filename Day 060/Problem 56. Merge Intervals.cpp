class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] - b[0] < 0;
        });

        vector<vector<int>> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};