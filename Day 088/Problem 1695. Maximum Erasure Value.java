import java.util.HashMap;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int result = 0;
        HashMap<Integer, Integer> countMap = new HashMap<>();
        int left = 0, sum = 0;

        for (int right = 0; right < nums.length; right++) {
            countMap.put(nums[right], countMap.getOrDefault(nums[right], 0) + 1);
            sum += nums[right];

            while (countMap.get(nums[right]) > 1) {
                sum -= nums[left];
                countMap.put(nums[left], countMap.get(nums[left]) - 1);
                left++;
            }

            result = Math.max(result, sum);
        }

        return result;
    }
}