class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find majority element using Boyer-Moore Voting
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Count total occurrences of the majority candidate
        int total = 0;
        for (int num : nums) {
            if (num == candidate) total++;
        }

        // Step 2: Try all split points
        int leftCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == candidate) leftCount++;
            int rightCount = total - leftCount;

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
