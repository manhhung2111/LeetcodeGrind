class Solution {
    public int maximumLength(int[] nums, int k) {
        int[][] dp = new int[k][k];
        int result = 0;

        for (int num : nums) {
            int currentRemainder = num % k;
            for (int prevRemainder = 0; prevRemainder < k; prevRemainder++) {
                dp[prevRemainder][currentRemainder] = dp[currentRemainder][prevRemainder] + 1;
                result = Math.max(result, dp[prevRemainder][currentRemainder]);
            }
        }
        
        return result;
    }
}