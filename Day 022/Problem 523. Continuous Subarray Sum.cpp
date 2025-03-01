class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        
        map<int, vector<int>> mp = {{0, {-1}}};
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int remainder = sum % k;
            if (remainder < 0) remainder += k;

            if (mp.find(remainder) != mp.end() && i - mp[remainder][0] > 1) {
                return true;
            }

            mp[remainder].push_back(i);
        }

        return false;
    }
};