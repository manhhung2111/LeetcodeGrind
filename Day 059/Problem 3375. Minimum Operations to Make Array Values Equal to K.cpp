class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int minNum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            minNum = min(minNum, nums[i]);
        }

        if (k > minNum) {
            return -1;
        }
        
        if (k == minNum) {
            return s.size() - 1;
        }

        return s.size();
    }
};