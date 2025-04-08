class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp = {{0, -1}};
        int sum = 0;

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1) ? 1 : -1;

            if (mp.find(sum) != mp.end()) {
                result = max(i - mp[sum], result);
            } else {
                mp[sum] = i;
            }
        }

        return result;
    }
};