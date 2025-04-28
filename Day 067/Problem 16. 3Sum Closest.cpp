class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long result = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    if (labs(result - target) > labs(sum - target)) {
                        result = sum;
                    }
                    while (left < nums.size() - 1 && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                } else if (sum > target) {
                    if (labs(result - target) > labs(sum - target)) {
                        result = sum;
                    }
                    while (right > 0 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                }
            }

            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }


        return result;
    }
};