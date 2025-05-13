class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int round = 0; round < t; round++) {
            vector<long long> tmp(26, 0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    tmp[0] = (tmp[0] + count[25]) % MOD;
                    tmp[1] = (tmp[1] + count[25]) % MOD;
                } else {
                    tmp[i + 1] = (tmp[i + 1] + count[i]) % MOD;
                }
            }

            count = tmp;
        }

        int result = 0;
        for (int item : count) {
            result = (result + item) % MOD;
        }

        return result;
    }
};