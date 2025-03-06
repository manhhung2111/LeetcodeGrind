class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid.size();
        vector<int> freq(n + 1 , 0); // 1 index

        int a = -1, b = -1;
        for (vector<int> row : grid) {
            for (int num : row) {
                freq[num]++;

                if (freq[num] == 2) {
                    a = num;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) {
                b = i;
                break;
            }
        }

        return {a, b};
    }
};