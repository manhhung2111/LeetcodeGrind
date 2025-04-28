class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int left = 0, right = 1;

        while (right < nums.size()) {
            if (nums[left] == nums[right]) {
                count++;
                if (count <= 2) {
                    nums[++left] = nums[right];
                }
            } else {
                nums[++left] = nums[right];
                count = 1;
            }

            right++;
        }

        return ++left;
    }
};