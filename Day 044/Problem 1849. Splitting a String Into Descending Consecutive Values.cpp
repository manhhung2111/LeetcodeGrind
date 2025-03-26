class Solution {
public:
    unsigned long long int strToInt(string s) {
        // Skip leading zeros
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        unsigned long long int num = 0;
        for (i = 0; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
        }

        return num;
    }

    bool solve(int index, string s, vector<unsigned long long int> &values) {
        if (index == s.size() && values.size() > 1 && values[values.size() - 1] + 1 == values[values.size() - 2]) {
            return true;
        }

        for (int i = index; i < s.size(); i++) {
            unsigned long long int value = strToInt(s.substr(index, i - index + 1));
            if (values.size() == 0 || value == values.back() - 1) {
                values.push_back(value);
                if (solve(i + 1, s, values)) {
                    return true;
                }

                values.pop_back();
            }
        }

        return false;
    }

    bool splitString(string s) {
        vector<unsigned long long int> values;
        
        return solve(0, s, values);
    }
};