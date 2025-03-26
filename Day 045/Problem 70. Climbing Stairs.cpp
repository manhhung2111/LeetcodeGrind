class Solution {
public:
    int climbStairs(int n) {
        map<int, int> step = {
            {0, 0},
            {1, 1},
            {2, 2},
        };
        for (int i = 3; i <= n; i++) {
            step[i]= step[i - 1] + step[i -2];
        }

        return step[n];
    }
};