class Solution {
private:
    int MOD = 1e9 + 7;
    int ALPHABETS = 26;

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> count(ALPHABETS, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int round = 0; round < t; round++) {
            vector<long long> temp(ALPHABETS, 0);
            for (int i = 0; i < ALPHABETS; i++) {
                for (int k = 1; k <= nums[i]; k++) {
                    temp[(i + k) % ALPHABETS] = (temp[(i + k) % ALPHABETS] + count[i]) % MOD;
                }
            }

            count = temp;
        }

        int result = 0;
        for (int cnt : count) {
            result = (result + cnt) % MOD;
        }

        return result;
    }
};