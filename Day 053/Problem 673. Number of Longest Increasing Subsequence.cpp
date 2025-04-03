class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 0);

        int lenLIS = 0, result = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int maxLen = 1, maxCnt = 1;

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    if (dp[j] + 1 > maxLen) {
                        maxLen = dp[j] + 1;
                        maxCnt = count[j];
                    } else if (dp[j] + 1 == maxLen) {
                        maxCnt += count[j];
                    }
                }
            }

            if (maxLen > lenLIS) {
                lenLIS = maxLen;
                result = maxCnt;
            } else if (maxLen == lenLIS) {
                result += maxCnt;
            }

            dp[i] = maxLen;
            count[i] = maxCnt;
        }

        return result;
    }
};