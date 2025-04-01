class Solution {
public:

    map<pair<int, int>, int> dp;
    bool solve(int index, int remaining, const vector<int>& nums) {
        if (remaining == 0) {
            return true;
        }

        if (remaining < 0 || index >= nums.size()) {
            return false;
        }

        if (dp.find({index, remaining}) != dp.end()) {
            return dp[{index, remaining}];
        }

        return dp[{index, remaining}] = solve(index + 1, remaining, nums) || solve(index + 1, remaining - nums[index], nums);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) 
            sum += num;
        
        if (sum & 1) return false;
        return solve(0, sum / 2, nums); 
    }
};