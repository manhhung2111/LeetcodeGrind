class Solution {
    public:
        int findMin(vector<int>& nums) {
            int low = 0, high = nums.size() - 1;
            int answer = nums[0];
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(nums[mid] >= nums[low]) {
                    answer = min(answer, nums[low]);
                    low = mid + 1;
                }else {
                    answer = min(answer, nums[mid]);
                    high = mid - 1;
                }
            }
            return answer;
        }
    };