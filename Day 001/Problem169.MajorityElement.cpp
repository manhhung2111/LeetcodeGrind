#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;

        for (int num : nums) {
            freq[num]++;

            if (freq[num] > nums.size() / 2) {
                return num;
            }
        }

        return -1;
    }
};