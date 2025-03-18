class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 0, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = (mid + 1) * mid / 2;

            if (sum == n) {
                return mid;
            } else if (sum < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (high == -1) return 1;
        return high;
    }
};