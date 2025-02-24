class Solution {
public:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j <= right-1; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }


    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;

        int pivot = partition(nums, left, right);   
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }


    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};