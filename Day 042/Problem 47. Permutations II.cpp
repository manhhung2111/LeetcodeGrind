class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> permutation, map<int, int> &count, int n) {
        if (permutation.size() == n) {
            result.push_back(permutation);
            return;
        }

        for (auto entry : count) {
            if (entry.second > 0) {
                count[entry.first]--;
                permutation.push_back(entry.first);

                dfs(permutation, count, n);

                count[entry.first]++;
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<int> permutation;

        dfs(permutation, count, nums.size());

        return result;
    }
};