class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) {
                    // Move  the right pointer to the next potential number, skip duplicates
                    while (right > 0 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (sum < 0) {
                    // Move the left pointer to the next potential number, skip duplicates
                    while (left < nums.size() - 1  && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                } else {
                    // Sum equals to zero
                    answer.push_back({nums[i], nums[left], nums[right]});

                    while (right > 0 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    while (left < nums.size() - 1  && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    right--; left++;
                }

            }

            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return answer;
    }
};