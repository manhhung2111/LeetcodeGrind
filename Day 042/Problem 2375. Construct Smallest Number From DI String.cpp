class Solution {
public:
    vector<string> result;
    void dfs(int index, string& combination, string pattern, vector<bool>& used) {
        if (index == pattern.size()) {
            result.push_back(combination);
            return;
        }

        if (pattern[index] == 'I') {
            for (int i = combination.back() - '0' + 1; i <= 9; i++) {
                if (used[i] == false) {
                    combination.push_back(i + '0');
                    used[i] = true;

                    dfs(index + 1, combination, pattern, used);

                    combination.pop_back();
                    used[i] = false;
                }
            }
        } else {
            for (int i = combination.back() - '0' - 1; i >= 1; i--) {
                if (used[i] == false) {
                    combination.push_back(i + '0');
                    used[i] = true;

                    dfs(index + 1, combination, pattern, used);

                    combination.pop_back();
                    used[i] = false;
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        vector<string> combinations;
        for (int i = 1; i <= 9; i++) {
            string temp = "";
            temp.push_back(i + '0');
            combinations.push_back(temp);
        }

        for (int i = 0; i < combinations.size(); i++) {
            vector<bool> used(10, false);
            used[i + 1] = true;
            dfs(0, combinations[i], pattern, used);
        }

        if (result.size() > 1)
            sort(result.begin(), result.end());
        return result[0];
    }
};