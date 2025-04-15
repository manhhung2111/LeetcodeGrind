class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0;
        string num = to_string(labs(x));

        long result = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            result = result * 10 + (num[i] - '0');
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        }

        return (int) result * (isNegative ? -1 : 1);
    }
};