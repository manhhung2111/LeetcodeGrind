#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;

        int start = 0, end = 0;
        while (start < nums.size() && end < nums.size()) {
            if (nums[start] && nums[end]) {
                start++; end++;
            } else if (!nums[start]){
                if (!nums[end]) {
                    end++;
                } else {
                    long long subarraySize = end - start;
                    answer += subarraySize * (subarraySize + 1) / 2;
                    start = end;
                }
            }
        }

        if (start < nums.size() && !nums[start]) {
            long long subarraySize = end - start;
            answer += subarraySize * (subarraySize + 1) / 2;
        }

        return answer;
    }
};