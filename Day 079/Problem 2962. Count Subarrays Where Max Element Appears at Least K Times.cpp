#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        
        int maxCandidate = *max_element(nums.begin(), nums.end());
        int countMax = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == maxCandidate) {
                countMax++;
            }

            while (countMax >= k) {
                if (nums[start] == maxCandidate) {
                    countMax--;
                }
                start++;
            }

            result += (long long)(end + 1) - (long long)(end - start + 1);
        }

        return result;
    }
};