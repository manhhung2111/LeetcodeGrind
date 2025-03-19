class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int missingNums = arr[mid] - mid - 1;
            if (missingNums == k) {
                index = mid;
                high = mid - 1;
            } else if (missingNums < k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (index == -1) return low + k;
        return index + k;
    }
};