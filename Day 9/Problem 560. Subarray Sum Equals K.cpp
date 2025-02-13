class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum = {0};

        map<int, int> mp;
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] + prefixSum[i];
            if (num == k) answer++;
            
            answer += mp[num - k];
            
            mp[num]++;
            prefixSum.push_back(num);
        }

        return answer;
    }
};