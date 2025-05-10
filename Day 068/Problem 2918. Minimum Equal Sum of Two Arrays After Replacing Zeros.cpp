class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int num : nums1) {
            sum1 += num;
            zeros1 += num == 0 ? 1 : 0;
        }
        for (int num : nums2) {
            sum2 += num;
            zeros2 += num == 0 ? 1 : 0;
        }

        if (sum1 + zeros1 > sum2 + zeros2 && zeros2 == 0) {
            return -1;
        }

        if (sum2 + zeros2 > sum1 + zeros1 && zeros1 == 0) {
            return -1;
        }

        return max(sum2 + zeros2, sum1 + zeros1);
    }
};