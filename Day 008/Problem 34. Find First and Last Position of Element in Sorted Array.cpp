class Solution {
    public:
        int findIndex(vector<int>& nums, int target, bool isLast) {
            int low = 0, high = nums.size() - 1;
    
            int index = -1;
            while (low <= high) {
                int middle = low + (high - low)/2;
    
                if (nums[middle] == target) {
                    index = middle;
                    if (isLast) {
                        low = middle + 1;
                    } else {
                        high = middle - 1;
                    }
                } else if (nums[middle] > target) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            }
    
            return index;
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
            int firstIndex = findIndex(nums, target, false);
    
            if (firstIndex == -1) {
                return {-1, -1};
            }
    
            int lastIndex = findIndex(nums, target, true);
            return {firstIndex, lastIndex};
        }
    };