class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);

            if (s[i] == part.back() && st.size() >= part.size() && helper(st, part)) {
                for (int j = 0; j < part.size(); j++) {
                    st.pop();
                }
            }
        }

        string answer = "";
        while (!st.empty()) {
            answer = st.top() + answer;
            st.pop();
        }

        return answer;
    }

    bool helper (stack<char> st, string part) {
        for (int i = part.size() - 1; i >= 0; i--) {
            if (part[i] != st.top()) {
                return false;
            }
            st.pop();
        }

        return true;
    }
};