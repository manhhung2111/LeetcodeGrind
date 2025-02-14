#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++; j++;
            } else {
                j++;
            }
        }

        while (i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};