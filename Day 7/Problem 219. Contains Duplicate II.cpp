class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                if (abs(lastIndex[nums[i]] - i) <= k) {
                    return true;
                }
            }
            lastIndex[nums[i]] = i;
        }

        return false;
    }
};