class Solution {
public:
    vector<vector<int>> result;

    void dfs(int index, vector<int> &candidates, vector<int> &combination, int &remainSum) {
        if (remainSum < 0) {
            return;
        }

        if (remainSum == 0) {
            result.push_back(combination);
        }

        for (int i = index; i < candidates.size(); i++) {
            remainSum -= candidates[i];
            combination.push_back(candidates[i]);

            dfs(i, candidates, combination, remainSum);

            remainSum += candidates[i];
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        dfs(0, candidates, combination, target);

        return result;
    }
};