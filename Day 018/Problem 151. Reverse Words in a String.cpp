class Solution {
public:
    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    string reverseWords(string s) {
        int slow = s.size() - 1, fast = s.size() - 1;

        string answer = "", temp = "";
        while (fast >= 0 && slow >= 0) {
            if (isAlphaNum(s[fast])) {
                temp = s[fast] + temp;
                fast--;
            } else {
                if (fast < slow) {
                    if (answer.size() > 0) answer += " ";
                    answer += temp;
                    temp = "";
                    fast--; slow = fast;
                } else {
                    fast--; slow--;
                }
            }
        }

        if (temp.size() > 0) {
            if (answer.size() > 0) answer += " ";
            answer += temp;
        }

        return answer;
    }
};