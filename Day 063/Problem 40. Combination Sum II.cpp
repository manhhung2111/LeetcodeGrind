class Solution {
public:
    vector<vector<int>> result;
    void solve(int index, const vector<int> &candidates, vector<int> &combination, int &remaining) {
        if (remaining == 0) {
            result.push_back(combination);
            return;
        }

        if (remaining < 0 || index >= candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            remaining -= candidates[i];
            combination.push_back(candidates[i]);

            solve(i + 1, candidates, combination, remaining);

            remaining += candidates[i];
            combination.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, combination, target);
        return result;
    }
};