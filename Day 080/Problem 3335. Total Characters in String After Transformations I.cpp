#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);

            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    temp[0] = (temp[0] + count[25]) % MOD;
                    temp[1] = (temp[1] + count[25]) % MOD;
                } else {
                    temp[i + 1] = (temp[i + 1] + count[i]) % MOD;
                }
            }

            count = move(temp);
        }

        int result = 0;
        for (int ele : count) {
            result = (result + ele) % MOD;
        }

        return result;
    }
};