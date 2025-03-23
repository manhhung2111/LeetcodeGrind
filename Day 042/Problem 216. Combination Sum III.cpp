class Solution {
public:
    vector<vector<int>> result;
    void dfs(int index, int k, vector<int> &combination, int &remain) {
        if (combination.size() == k && remain == 0) {
            result.push_back(combination);
            return;
        }

        if (remain < 0 || combination.size() > k) {
            return;
        }

        for (int i = index; i <= 9; i++) {
            combination.push_back(i);
            remain -= i;

            dfs(i + 1, k, combination, remain);

            combination.pop_back();
            remain += i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        dfs(1, k, combination, n);

        return result;
    }
};