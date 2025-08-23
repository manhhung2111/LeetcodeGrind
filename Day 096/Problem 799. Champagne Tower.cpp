#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int ROWS = 100;

    double champagneTower(int poured, int query_row, int query_glass) {
        const int ROWS = 101; // max 100, +1 safety
        vector<vector<double>> tower(ROWS, vector<double>(ROWS, 0.0));

        tower[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double overflow = max(0.0, tower[i][j] - 1.0);
                if (overflow > 0 && i + 1 < ROWS) {
                    tower[i + 1][j] += overflow / 2;
                    tower[i + 1][j + 1] += overflow / 2;
                    tower[i][j] = 1.0;
                }
            }
        }

        return tower[query_row][query_glass];
    }
};