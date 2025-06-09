class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainders;
        remainders[0] = -1;

        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            
            if (remainders.find(remainder) == remainders.end()) {
                remainders[remainder] = i;
            }

            if (i - remainders[remainder] > 1) {
                return true;
            }
        }

        return false;
    }
};