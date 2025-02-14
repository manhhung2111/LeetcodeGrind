class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = INT_MIN;
        map<int, int> freq;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (right - left + 1 - k > freq[1]) {
                freq[nums[left]]--;
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};