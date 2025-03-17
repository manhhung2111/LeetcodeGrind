class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            int low = 0, high = grid[i].size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (grid[i][mid] >= 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            result += grid[i].size() - low;
        }

        return result;
    }
};