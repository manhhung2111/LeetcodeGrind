class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        array<int, 2> remainders = {1, 0};
        int sum = 0;
        int result = 0;

        for (int num : arr) {
            sum += num;
            int remainder = (sum & 1);
            result = (result + remainders[!remainder]) % MOD;
            remainders[remainder]++;
        }

        return result;
    }
};