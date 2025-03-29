class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int prodMax = 1, prodMin = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(prodMax, prodMin);
            }

            prodMax = max(nums[i], prodMax * nums[i]);
            prodMin = min(nums[i], prodMin * nums[i]);
            result = max(result, prodMax);
        }

        return result;
    }