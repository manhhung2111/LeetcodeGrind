class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count = {{0, 1}}; // {remainder, freq}
        
        int result = 0;
        long sum = 0;
        for (int num : nums) {
            sum += num;
            int remainder = sum % k;
            if (remainder < 0) remainder += k;
            result += count[remainder];
            count[remainder]++;
        }

        return result;
    }
};