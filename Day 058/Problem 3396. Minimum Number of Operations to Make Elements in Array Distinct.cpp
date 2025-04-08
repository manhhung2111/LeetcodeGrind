class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        int lastDupIdx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (count.find(nums[i]) != count.end()) {
                lastDupIdx = max(lastDupIdx, count[nums[i]]);
            }
            count[nums[i]] = i;
        }

        if (lastDupIdx == -1) {
            return 0;
        }

        int operations = (lastDupIdx + 1) / 3;
        int remainder = (lastDupIdx + 1) % 3;

        return operations + (remainder > 0 ? 1 : 0);
    }
};