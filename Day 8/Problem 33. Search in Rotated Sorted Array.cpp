class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1;
    
            while (low <= high) {
                int middle = low + (high - low)/2;
    
                if (nums[middle] == target) {
                    return middle;
                } else if (nums[low] <= nums[middle]) {
                    // Left array is sorted
                    if (nums[low] <= target && target < nums[middle]) {
                        high = middle - 1;
                    } else {
                        low = middle + 1;
                    }
                } else {
                    // Right array is sorted
                    if (nums[middle] < target && nums[high] >= target) {
                        low = middle + 1;
                    } else {
                        high = middle - 1;
                    }
                }
            }
    
            return -1;
        }
    };