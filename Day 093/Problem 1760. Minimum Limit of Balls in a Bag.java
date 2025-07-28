class Solution {

    private boolean validBagSize(int[] nums, int bagSize, int maxOperations) {
        int operations = 0;
        for (int i = 0; i < nums.length; i++) {
            operations += (nums[i] + bagSize - 1) / bagSize - 1;
            if (operations > maxOperations) return false;
        }

        return true;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        int low = 1;
        int high = Integer.MIN_VALUE;
        for (int num : nums) high = Math.max(high, num);

        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (validBagSize(nums, mid, maxOperations)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
}