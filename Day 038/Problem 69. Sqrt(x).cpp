class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (high == -1) return 0;
        return high;
    }
};