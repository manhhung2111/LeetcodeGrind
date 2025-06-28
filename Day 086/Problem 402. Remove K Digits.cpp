class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n || num == "0") return "0";
        
        stack<char> stk;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !stk.empty() && stk.top() > num[i]) {
                k--;
                stk.pop();
            }
            stk.push(num[i]);

            if(stk.size() == 1 && num[i] == '0') stk.pop();
        }

        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string result = "";
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }

        if (result.size() == 0) {
            return "0";
        }

        reverse(result.begin(), result.end());
        return result;
    }
};