class Solution {
    private int countValidSequence(int[] nums, int[] remainders) {
        int result = 0;
        int index = 0;

        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] & 1) == remainders[index]) {
                result++;
                index = (index + 1) % remainders.length;
            }
        }

        return result;
    }
    
    public int maximumLength(int[] nums) {
        int r1 = countValidSequence(nums, new int[]{0, 0});
        int r2 = countValidSequence(nums, new int[]{0, 1});
        int r3 = countValidSequence(nums, new int[]{1, 0});
        int r4 = countValidSequence(nums, new int[]{1, 1});

        return Math.max(r1, Math.max(r2, Math.max(r3, r4)));
    }
}