import java.util.Arrays;

class Solution {

    private int lowerBound(int left, int right, int[] nums, int bound) {
        int index = nums.length;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= bound) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return index;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long result = 0;
        for (int i = 0; i < nums.length; i++) {
            int lowerIndex = this.lowerBound(i + 1, nums.length - 1, nums, lower - nums[i]);
            int upperIndex = this.lowerBound(i + 1, nums.length - 1, nums, upper - nums[i] + 1);

            result += upperIndex - lowerIndex;
        }

        return result;
    }
}