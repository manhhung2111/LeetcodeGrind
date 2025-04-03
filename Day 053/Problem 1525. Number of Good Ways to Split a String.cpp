class Solution {
public:
    int numSplits(string s) {
        int n = s.size();

        unordered_map<int, int> left, right;
        vector<int> uniqueLeft(n), uniqueRight(n);
        
        for (int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[n - i - 1]]++;

            uniqueLeft[i] = left.size();
            uniqueRight[n - i - 1] = right.size();
        }

        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            result += uniqueLeft[i] == uniqueRight[i + 1];
        }

        return result;
    }
};