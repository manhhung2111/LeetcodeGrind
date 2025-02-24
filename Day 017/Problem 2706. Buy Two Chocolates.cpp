class Solution {
public:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j <= right -1; j++) {
            if (nums[j] <= pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;

        int pivotIndex = partition(nums, left, right);
        quickSort(nums, left, pivotIndex-1);
        quickSort(nums, pivotIndex+1, right);
    }

    int buyChoco(vector<int>& prices, int money) {
        quickSort(prices, 0, prices.size()-1);

        if (prices[0] + prices[1] > money) {
            return money;
        }

        return money - prices[0] - prices[1];
    }
};