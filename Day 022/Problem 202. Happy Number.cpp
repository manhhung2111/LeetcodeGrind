class Solution {
public:
    int genNext(int n) {
        int result = 0;

        while (n) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }

        return result;
    }

    bool isHappy(int n) {
        map<int, bool> visited;
        visited[n] = true;

        while (n != 1) {
            n = genNext(n);
            if (visited[n]) return false;
            visited[n] = true;
        }

        return true;
    }
};