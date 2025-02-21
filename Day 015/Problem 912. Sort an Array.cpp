class Solution {
public:
    void merge(vector<int> &arr, int l, int m, int r) {
        // Copy an array
        vector<int> nums1 (m - l + 1), nums2 (r - m);

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = arr[l + i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            nums2[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                arr[l++] = nums1[i++];
            } else {
                arr[l++] = nums2[j++];
            }
        }

        while (i < nums1.size()) {
            arr[l++] = nums1[i++];
        }

        while (j < nums2.size()) {
            arr[l++] = nums2[j++];
        }
    }

    void mergeSort(vector<int> &arr, int l, int r) {
        if (l >= r) return;
        int m = l + (r -l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};