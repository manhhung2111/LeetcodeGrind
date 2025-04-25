class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++) {
            // Remove invalid elements from the front
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements from the back
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};