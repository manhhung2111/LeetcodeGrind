class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0), suffix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        vector<int> result;
        for (int i = 1; i <= n; i++) {
            int left = (i - 1) * nums[i - 1] - prefix[i - 1];
            int right = suffix[i] - (n - i) * nums[i - 1];

            result.push_back(left + right);
        }
        
        return result;
    }
};