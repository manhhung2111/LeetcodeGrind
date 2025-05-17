class Solution {
public:
    /**
     * Priority queue approach
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Retain k smallest difference
        priority_queue<pair<int, int>> minHeap;
        for (int num : arr) {
            minHeap.push({abs(num - x), num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
     */
    
    // Two pointers aproach
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while (right - left + 1 > k) {
            if (x - arr[left] <= arr[right] - x) right--;
            else left++;
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};