class Solution {
    public:
        bool isOperator(string token) {
            return token == "+" || token == "-" || token == "*" || token == "/";
        }
    
        int toInt(string str) {
            bool isNegative = false;
            int index = 0;
    
            if (str[0] == '-') {
                index = 1;
                isNegative = true;
            }
    
            int number = 0;
            while (index < str.size()) {
                number += (str[index] - '0') * pow(10, str.size() - 1 - index);
                index++;
            }
    
            return isNegative ? -1 * number : number;
        }
    
    
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
    
            for (string token : tokens) {
                if (isOperator(token)) {
                    int num2 = st.top(); st.pop();
                    int num1 = st.top(); st.pop();
    
                    int result = 0;
                    if (token == "+") {
                        result = num1 + num2;
                    } else if (token == "-") {
                        result = num1 - num2;
                    } else if (token == "*") {
                        result = num1 * num2;
                    } else {
                        result = num1 / num2;
                    }
    
                    st.push((result));
                } else {
                    st.push(toInt(token));
                }
            }
    
            return st.top();
        }
    };