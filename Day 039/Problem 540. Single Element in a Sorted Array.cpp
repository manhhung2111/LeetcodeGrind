class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();
        if (nums[0] != nums[1]) return nums[0];
        if (nums.back() != nums[nums.size() - 2]) return nums.back();

        int low = 1, high = nums.size() - 2;

        while (low <= high) {
            // cout << "Low: " << low << ", " << "High: " << high << endl;
            int mid = low + (high - low)/2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if (mid & 1) {
                if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else if (!(mid & 1)){
                if (nums[mid] == nums[mid+1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};