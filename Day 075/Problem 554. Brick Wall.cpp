class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int result = n;

        unordered_map<long, int> count;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                sum += wall[i][j];
                count[sum]++;

                if (j == wall[i].size() - 1) continue;
                result = min(result, n - count[sum]);
            }
        }

        return result;
    }
};