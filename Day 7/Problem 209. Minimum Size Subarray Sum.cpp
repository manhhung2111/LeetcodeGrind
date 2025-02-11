class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT_MAX;

        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                answer = min(answer, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return answer == INT_MAX ? 0 : answer;
    }
};