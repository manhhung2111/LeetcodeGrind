class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> mp;
        
        for (vector<int> rectangle : rectangles) {
            int width = rectangle[0], height = rectangle[1];
            double ratio = 1.0 * width / height;

            mp[ratio]++;
        }

        long long result = 0;
        for (auto entry : mp) {
            result += entry.second * (entry.second - 1) / 2;
        }

        return result;
    }
};