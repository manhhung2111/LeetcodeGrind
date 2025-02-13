class NumArray {
public:
    vector<int> prefixSum = {0};

    NumArray(vector<int>& nums) {
        for (int num : nums) {
            prefixSum.push_back(num + prefixSum.back());
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */