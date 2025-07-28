import java.util.Arrays;

class Solution {

    private int countValidPairs(int[] nums, int threshold) {
        int pairs = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] - nums[i] < threshold) {
                i++;
                pairs++;
            }
        }

        return pairs;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int low = 0, high = nums[nums.length - 1] - nums[0];

        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pairs = countValidPairs(nums, mid);

            if (pairs >= p) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
}