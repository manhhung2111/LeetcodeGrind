class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        long num = labs(n);

        double result = 1;
        while (num) {
            if (num & 1) {
                result *= x;
            }
            x *= x;
            num >>= 1;
        }

        return result;
    }
};