class Solution {
public:
    vector<vector<int>> result;

    void dfs(int index, vector<int> &combination, vector<int> &candidates, int &remainSum) {
        if (remainSum < 0) {
            return;
        }

        if (remainSum == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue; // skip duplicate

            combination.push_back(candidates[i]);
            remainSum -= candidates[i];

            dfs(i + 1, combination, candidates, remainSum);

            combination.pop_back();
            remainSum += candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() > 1) sort(candidates.begin(), candidates.end());
        vector<int> combination;

        dfs(0, combination, candidates, target);

        return result;
    }
};