class Solution {
public:

    bool solve(int index, int k, int sum, const int &target, const vector<int> &nums, vector<bool> &visited) {
        if (k == 0) {
            return true;
        }

        if (sum == target) {
            return solve(0, k - 1, 0, target, nums, visited);
        }

        for (int i = index; i < nums.size(); i++) {
            if (!visited[i]) {  
                visited[i] = true;
                if (solve(i + 1, k, sum + nums[i], target, nums, visited)) {
                    return true;
                }
                visited[i] = false;

                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int accumulateSum = 0;
        for (int num : nums) {
            accumulateSum += num;
        }

        if (accumulateSum % k != 0) return false;

        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return solve(0, k, 0, accumulateSum / k, nums, visited);
    }
};