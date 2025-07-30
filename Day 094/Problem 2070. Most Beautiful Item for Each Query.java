import java.util.Arrays;

class Solution {
    private int upperBound(int[][] items, int price) {
        int index = -1;
        int low = 0, high = items.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (items[mid][0] <= price) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return index;
    }

    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0])); // sort by price

        // Store the most beautiful item till ith index
        for (int i = 1; i < items.length; i++) {
            items[i][1] = Math.max(items[i][1], items[i - 1][1]);
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int index = this.upperBound(items, queries[i]);
            if (index != -1) {
                result[i] = items[index][1];
            }
        }

        return result;
    }
}