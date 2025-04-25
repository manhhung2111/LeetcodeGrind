class Solution {
public:

    int digitsSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            mp[digitsSum(i)]++;
        }

        int largestSize = 0, result = 0;
        for (auto entry : mp) {
            if (entry.second > largestSize) {
                result = 1;
                largestSize = entry.second;
            } else if (entry.second == largestSize) {
                result++;
            }
        }

        return result;
    }
};