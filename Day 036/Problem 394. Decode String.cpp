class Solution {
public:
    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }

    string decodeString(string s) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                // Get the string within '[' and ']'
                string substr = "";
                while (!st.empty() && st.top() != '[') {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();

                // Get the number
                string count = "";
                while (!st.empty() && isNum(st.top())) {
                    count = st.top() + count;
                    st.pop();
                }

                int k = stoi(count);
                while (k--) {
                    for (char c : substr) {
                        st.push(c);
                    }
                }
            }
        }

        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};