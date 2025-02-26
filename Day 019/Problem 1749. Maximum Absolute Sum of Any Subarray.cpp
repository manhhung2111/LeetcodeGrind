class Solution {
public:
    int helper(const vector<int> &arr, bool maximum) {
        int sum = 0;
        int answer = maximum ? INT_MIN : INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            if (maximum) {
                sum = max(sum + arr[i], arr[i]);
                answer = max(sum, answer);
            } else {
                sum = min(sum + arr[i], arr[i]);
                answer = min(sum, answer);
            }
        }

        return abs(answer);
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        return max(0, max(helper(nums, true), helper(nums, false)));
    }
};