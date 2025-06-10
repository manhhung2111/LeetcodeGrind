class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> delta(n + 1, 0);
        for (vector<int> shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                delta[start]++;
                delta[end + 1]--;
            } else {
                delta[start]--;
                delta[end + 1]++;
            }
        }

        int operations = 0;
        for (int i = 0; i < n; i++) {
            operations += delta[i];
            int moves = (s[i] - 'a' + operations) % 26;
            if (moves < 0) moves += 26;
            s[i] = moves + 'a';
        }

        return s;
    }
};