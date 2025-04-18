class Solution {
public:
    vector<vector<int>> result;
    void solve(int index, vector<int> &nums, vector<int> &subset) {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            solve(i + 1, nums, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        solve(0, nums, subset);
        return result;
    }
};