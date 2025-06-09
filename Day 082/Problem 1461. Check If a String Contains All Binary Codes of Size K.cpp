class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> combinations;

        int left = 0;
        string combination = "";

        for (int right = 0; right < s.size(); right++) {
            combination.push_back(s[right]);

            if (right - left + 1 == k) {
                combinations.insert(combination);
                combination.erase(combination.begin());
                left++;
            }
        }

        int total = 1 << k;

        return combinations.size() == total;
    }
};