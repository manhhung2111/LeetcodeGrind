class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int firstNum = INT_MAX, secondNum = INT_MAX;

        for (int num : nums) {
            if (firstNum >= num) {
                firstNum = num;
            } else if (secondNum >= num) {
                secondNum = num;
            } else {
                return true;
            }
        }

        return false;
    }
};