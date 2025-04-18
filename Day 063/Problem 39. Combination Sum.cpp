class Solution {
public:
    vector<vector<int>> combinations;
    void solve(int index, vector<int> candidates, int &remaining, vector<int> &combination) {
        if (remaining == 0) {
            combinations.push_back(combination);
            return;
        }

        if (remaining < 0 || index >= candidates.size()) {
            return;
        } 
        
        for (int i = index; i < candidates.size(); i++) {
            remaining -= candidates[i];
            combination.push_back(candidates[i]);
            solve(i, candidates, remaining, combination);
            remaining += candidates[i];
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        solve(0, candidates, target, combination);

        return combinations;
    }
};