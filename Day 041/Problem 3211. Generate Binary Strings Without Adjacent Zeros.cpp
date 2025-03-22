class Solution {
public:
    vector<string> result;
    void dfs(string combination, int n) {
        if (combination.size() == n) {
            result.push_back(combination);
            return;
        }

        combination.push_back('1');
        dfs(combination, n);
        combination.pop_back();

        if (combination.size() == 0 || combination.back() == '1') {
            combination.push_back('0');
            dfs(combination, n);
            combination.pop_back();
        }
    }
    
    
    vector<string> validStrings(int n) {
        string combination = "";
        dfs(combination, n);

        return result;
    }
};