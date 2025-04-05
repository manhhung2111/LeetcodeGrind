class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s (nums.begin(), nums.end());

        int result = 1;
        for (int num : s) {

            if (s.find(num - 1) == s.end()) {
                int count = 1;
                int item = num;

                while (s.find(item + 1) != s.end()) {
                    count++;
                    item++;
                }

                result = max(result, count);
            }
        }

        return result;
    }
};
