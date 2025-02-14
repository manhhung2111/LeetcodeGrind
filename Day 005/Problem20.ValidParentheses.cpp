class Solution {
    public:
        bool isValid(string s) {
            map<char, char> mp = {
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
            };
            stack<char> st;
            for(int i = 0; i < s.size(); i++) {
                if(st.empty() || mp.find(s[i]) != mp.end()) {
                    st.push(s[i]);
                } else {
                    if(s[i] == mp[st.top()]) st.pop();
                    else return false;
                }
            }
            return st.empty();
        }
    };