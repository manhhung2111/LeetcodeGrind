class Solution {
public:

    vector<vector<int>> result;
    void solve(int index, vector<int> &nums, vector<int> &subset) {
        result.push_back(subset);

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            solve(i + 1, nums, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(0, nums, subset);
        return result;
    }
};