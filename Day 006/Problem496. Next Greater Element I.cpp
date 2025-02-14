class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            map<int, int> nextGreater;
    
            stack<int> st;
            for (int i = 0; i < nums2.size(); i++) {
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    int idx = st.top(); st.pop();
                    nextGreater[nums2[idx]] = nums2[i];
                }
    
                st.push(i);
            }
    
            vector<int> answer;
            for (int num : nums1) {
                if (nextGreater[num]) {
                    answer.push_back(nextGreater[num]);
                } else {
                    answer.push_back(-1);
                }
            }
    
            return answer;
        }
    };