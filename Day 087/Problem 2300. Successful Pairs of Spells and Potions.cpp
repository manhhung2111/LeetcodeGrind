class Solution {
public:
    int binarySearch(const vector<int> &arr, long long num) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= num) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;

        for (int i = 0; i < spells.size(); i++) {
            if (spells[i] == 0) { // handle zero spell edge case
                result.push_back(0);
                continue;
            }
            long long num = (success + spells[i] - 1) / spells[i]; // integer ceil
            int index = binarySearch(potions, num);
            result.push_back(index == -1 ? 0 : potions.size() - index);
        }

        return result;
    }
};
