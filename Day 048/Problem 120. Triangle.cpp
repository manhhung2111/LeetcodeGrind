class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        int index = triangle.size() - 2;
        
        while (index >= 0) {
            vector<int> temp;
            for (int i = 0; i < triangle[index].size(); i++) {
                temp.push_back(min(dp[i], dp[i+1]) + triangle[index][i]);
            }

            dp = temp;
            index--;
        }

        int result = INT_MAX;
        for (int sum : dp) {
            result = min(result, sum);
        }

        return result;
    }
};