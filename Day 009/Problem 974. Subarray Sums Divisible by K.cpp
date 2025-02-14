class Solution {
public:
    /**
    * When two subarrays have the same remainder when divided by k. It means that the subarray between these 2 positions are divisible by K
    */
    int subarraysDivByK(vector<int>& nums, int k) {
        long sum = 0;
        map<int, int> mp = {{0, 1}};

        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int remainder = sum % k;
            if (remainder < 0) remainder += k;

            answer += mp[remainder];
            mp[remainder]++;
        }

        return answer;
    }
};