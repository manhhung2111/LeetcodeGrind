class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        long ltarget = (long)target;

        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int left = j + 1, right = nums.size() - 1;

                while (left < right) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if (sum == ltarget) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;

                        while (right > left && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < ltarget) {
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                    } else {
                        while (right > left && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    }
                }

                while (j < nums.size() - 3 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }

            while (i < nums.size() - 4 && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return result;
    }
};