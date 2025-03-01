class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifts = 0;

        while (left != right) {
            shifts++;

            left = left >> 1;
            right = right >> 1;
        }

        return left << shifts;
    }
};