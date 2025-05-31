#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> maxSuffix(n, nums.back());
        int suffixSum = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            suffixSum += nums[i];
            maxSuffix[i] = max(suffixSum, maxSuffix[i + 1]);
        }

        vector<int> maxPrefix(n, nums.front());
        int prefixSum = nums.front();
        int specialSum = maxPrefix[0] + maxSuffix[1];

        for (int i = 1; i < n - 1; i++) {
            prefixSum += nums[i];
            maxPrefix[i] = max(prefixSum, maxPrefix[i - 1]);
            specialSum = max(specialSum, maxPrefix[i] + maxSuffix[i + 1]);
        }

        int normalSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            normalSum = max(normalSum, sum);
        }

        return max(normalSum, specialSum);
    }
};