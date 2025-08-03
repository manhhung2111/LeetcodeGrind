import java.util.PriorityQueue;

class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        // 1st iteration to maximize the sum of nums1
        PriorityQueue<Integer> pq1 = new PriorityQueue<>(
            (a, b) -> nums1[a] - nums1[b]
        ); // min heap based on the index

        for (int i = 0; i < nums1.length; i++) {
            pq1.offer(i);
            if (pq1.size() > k) pq1.poll();
        }

        long sum = 0, multiplier = 0;
        while (!pq1.isEmpty()) {
            int index = pq1.poll();
            System.out.print(index + ", ");
            sum += nums1[index];
            multiplier = Math.max(multiplier, nums2[index]);
        }

        long result1 = sum * multiplier;

        // 2nd iteration to maximize the min of nums2
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(
            (a, b) -> nums2[a] - nums2[b]
        ); // min heap based on the index

        for (int i = 0; i < nums2.length; i++) {
            pq2.offer(i);
            if (pq2.size() > k) pq2.poll();
        }

        sum = 0; multiplier = 0;
        System.out.println();
        while (!pq2.isEmpty()) {
            int index = pq2.poll();
            System.out.print(index + ", ");
            sum += nums1[index];
            multiplier = Math.max(multiplier, nums2[index]);
        }

        long result2 = sum * multiplier;

        return Math.max(result1, result2);
    }
}