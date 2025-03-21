class Solution {
public:
    
    void dfs(vector<int> &nums, vector<int> &permutation, vector<vector<int>> &permutations, set<int> &visited) {
        if (permutation.size() == nums.size()) {
            permutations.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(nums[i]) == visited.end()) {
                permutation.push_back(nums[i]);
                visited.insert(nums[i]);
                dfs(nums, permutation, permutations, visited);

                visited.erase(nums[i]);
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        vector<vector<int>> permutations;
        set<int> visited;

        dfs(nums, permutation, permutations, visited);

        return permutations;
    }
};