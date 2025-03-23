class Solution {
public:
    vector<vector<int>> result;
    void dfs(int index, int k, int n, vector<int> &combination) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i <= n - k + index && i <= n; i++) {
            combination.push_back(i);
            dfs(i + 1, k, n, combination);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        dfs(1, k, n, combination);
        return result;
    }
};