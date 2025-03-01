class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> freq = {{0, 1}};
        int sum = 0, result = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int remainder = sum % k;
            remainder += remainder < 0 ? k : 0;
            result += freq[remainder];

            freq[remainder]++;
        }

        return result;
    }
};