class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> answer (nums.size(), -1);

        long long sum = 0;
        for (int i = 0; i < k* 2 && i < nums.size(); i++) {
            sum += nums[i];
        }

        for (int i = k * 2; i < nums.size(); i++) {
            if (i - k*2 - 1 >= 0) sum -= nums[i - k*2 - 1];
            sum += nums[i];
            
            answer[i - k] = (int) (sum / (2 * k + 1));
        }

        return answer;
    }
};