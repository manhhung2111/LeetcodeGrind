class Solution {
public:
    vector<vector<int>> result;
    void solve(int number, vector<int> &combination, int &remaining, const int &k) {
        if (combination.size() == k) {
            if (remaining == 0) {
                result.push_back(combination);
            }

            return;
        }

        for (int i = number; i <= 9; i++) {
            remaining -= i;
            combination.push_back(i);

            solve(i + 1, combination, remaining, k);

            remaining += i;
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        solve(1, combination, n, k);
        
        return result;
    }
};