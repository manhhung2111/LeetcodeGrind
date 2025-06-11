class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixN(n + 1, 0); // N count from 0 to i-1
        vector<int> suffixY(n + 1, 0); // Y count from i to n-1

        // prefix: total 'N' from 0 to i-1
        for (int i = 0; i < n; ++i) {
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');
        }

        // suffix: total 'Y' from i to n-1
        for (int i = n - 1; i >= 0; --i) {
            suffixY[i] = suffixY[i + 1] + (customers[i] == 'Y');
        }

        // Now, try each possible closing time i (from 0 to n)
        int bestHour = 0, minPenalty = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};
