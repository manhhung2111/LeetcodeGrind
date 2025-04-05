class Solution {
public:
    
    int solve(int index, const vector<int> &nums, int total) {
        if (index == nums.size()) {
            return total;  
        }

        int take = solve(index + 1, nums, total ^ nums[index]);
        int skip = solve(index + 1, nums, total);

        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};