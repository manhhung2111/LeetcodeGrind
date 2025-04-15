class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 5; i <= n; i += 5) {
            int temp = i;
            while (temp > 0 && temp % 5 == 0) {
                result += 1;
                temp /= 5;
            }
        }

        return result;
    }
};