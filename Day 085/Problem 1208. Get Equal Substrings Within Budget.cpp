class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int result = 0;
        for (int right = 0; right < s.size(); right++) {
            int cost = abs(s[right] - t[right]);
            while (maxCost < cost) {
                maxCost += abs(s[left] - t[left]);
                left++;
            }

            maxCost -= cost;
            result = max(result, right - left + 1);
        }

        return result;
    }
};