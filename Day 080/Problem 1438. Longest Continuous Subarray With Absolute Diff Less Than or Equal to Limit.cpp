class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQueue, minQueue;

        int start = 0;
        int result = 1;

        for (int end = 0; end < nums.size(); end++) {
            while (!maxQueue.empty() && maxQueue.front() < start) {
                maxQueue.pop_front();
            }

            while (!minQueue.empty() && minQueue.front() < start) {
                minQueue.pop_front();
            }

            while (!maxQueue.empty() && nums[maxQueue.back()] < nums[end]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(end);

            while (!minQueue.empty() && nums[minQueue.back()] > nums[end]) {
                minQueue.pop_back();
            }
            minQueue.push_back(end);

            while (!maxQueue.empty() && !minQueue.empty() && nums[maxQueue.front()] - nums[minQueue.front()] > limit) {
                if (start == maxQueue.front()) {
                    maxQueue.pop_front();
                } else if (start == minQueue.front()) {
                    minQueue.pop_front();
                }

                start++;
            }

            result = max(result, end - start + 1);
        }

        return result;
    }
};