class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long sum = 0;
        map<int, int> mp = {{0, -1}}; // Store the first index of the remainder

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int remainder = sum % k;
            if (remainder < 0) remainder += k;

            if (mp.find(remainder) != mp.end()) {
                if ((i - mp[remainder]) > 1) return true;
            } else {
                mp[remainder] = i;
            }
        }

        return false;
    }
};