class Solution {
    public:
        bool find132pattern(vector<int>& nums) {
            stack<pair<int, int>> st; // Stores <num_index, index of min number till the num_index>
    
            for (int i = 0; i < nums.size(); i++) {
                int minIndex = i;
    
                // For every number greater than the number in the top of the stack. We pop then update the minIndex for current number
                while (!st.empty() && nums[i] > nums[st.top().first]) {
                    pair<int, int> num = st.top(); st.pop();
                    minIndex = nums[minIndex] < nums[num.second] ? minIndex : num.second;
                }
    
                // Check if the current number is less than the top of the stack but still greater than the min number until the top of the stack
                if (!st.empty() && st.top().first != st.top().second) {
                    if (nums[i] < nums[st.top().first] && nums[i] > nums[st.top().second]) {
                        return true;
                    }
                }
    
                st.push({i, minIndex});
    
            }
    
            return false;
        }
    };