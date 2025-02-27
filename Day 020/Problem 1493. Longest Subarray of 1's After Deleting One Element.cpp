class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int, int> freq;
        int answer = 0;

        int left = 0, right = 0;
        while (right < nums.size()) {
            freq[nums[right]]++;

            while (freq[1] + 1 < right - left + 1) {
                answer = max(answer, freq[1]);
                freq[nums[left]]--;
                left++;
            }

            right++;
        }

        answer = max(answer, freq[1]);

        return answer == nums.size() ? nums.size() - 1 : answer;
    }
};