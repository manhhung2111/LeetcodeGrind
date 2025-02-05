#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct = {1}, postfixProduct = {1};
        
        for (int i = 0; i < nums.size(); i++) {
            prefixProduct.push_back(prefixProduct[i] * nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            postfixProduct.push_back(nums[i] * postfixProduct[nums.size() - 1 - i]);
        }

        reverse(postfixProduct.begin(), postfixProduct.end());

        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer.push_back(prefixProduct[i] * postfixProduct[i+1]);
        }

        return answer;
    }
};