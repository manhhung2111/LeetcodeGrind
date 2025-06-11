class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        // Step 1: Count frequencies and track max frequency
        for (int num : nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }

        // Step 2: Prepare result matrix with maxFreq rows
        vector<vector<int>> result(maxFreq);

        // Step 3: Distribute numbers across rows
        for (auto& [num, count] : freq) {
            for (int i = 0; i < count; ++i) {
                result[i].push_back(num);
            }
        }

        return result;
    }
};
