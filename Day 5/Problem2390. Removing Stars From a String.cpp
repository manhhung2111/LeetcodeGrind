class Solution {
    public:
        string removeStars(string s) {
            string answer = "";
    
            for (char c : s) {
                if (c == '*') {
                    answer.pop_back();
                } else {
                    answer.push_back(c);
                }
            }
    
            return answer;
        }
    };