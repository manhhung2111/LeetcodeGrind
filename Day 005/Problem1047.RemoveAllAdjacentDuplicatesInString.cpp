class Solution {
    public:
        string removeDuplicates(string s) {
            stack<char> st;
    
            for (char c : s) {
                if (!st.empty() && st.top() == c) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
    
            string answer = "";
            while(!st.empty()) {
                answer = st.top() + answer;
                st.pop();
            }
    
            return answer;
        }
    };