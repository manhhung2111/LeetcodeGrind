class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= nums[low]) {
                result = min(result, nums[low]);
                low = mid + 1;
            } else {
                result = min(result, nums[mid]);
                high = mid - 1;
            }
        }

        return result;
    }
};