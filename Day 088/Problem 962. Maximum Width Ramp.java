class Solution {
    public int maxWidthRamp(int[] nums) {
        // Using two pointers approach

        int n = nums.length;

        int[] rightMax = new int[n];
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], nums[i]);
        }

        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right++) {
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }

            result = Math.max(result, right - left);
        }

        return result;
    }
}