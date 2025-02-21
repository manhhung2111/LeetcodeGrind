class Solution {
public:
    void merge(vector<int> &arr, int l, int m, int r) {
        vector<int> nums1(m - l + 1), nums2(r - (m + 1) + 1);

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = arr[l + i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            nums2[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]){
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
        int m = l + (r - l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    int maximumGap(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        
        int answer = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            answer = max(nums[i+1] - nums[i], answer);
        }

        return answer;
    }
};