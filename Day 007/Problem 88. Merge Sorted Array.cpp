class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // We will merge the two arrays backward
        
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        
        while(j >= 0) {
            if(i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
};