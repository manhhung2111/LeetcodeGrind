class Solution {
public:

    int count = 0;
    void solve(int index, vector<string> &arr, set<char> &freq) {
        int total = freq.size();
        count = max(count, total);
        if (index == arr.size()) {
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (isValid(arr[i], freq)) {
                for (char c : arr[i]) {
                    freq.insert(c);
                }

                solve(i + 1, arr, freq);

                for (char c : arr[i]) {
                    freq.erase(c);
                }
            }
        }
    }

    bool isValid(string str, set<char> freq) {
        for (int j = 0; j < str.size(); j++) {
            if (freq.find(str[j]) != freq.end()) {
                return false;
            }
            freq.insert(str[j]);
        }

        return true;
    }

    int maxLength(vector<string>& arr) {
        set<char> freq;
        solve(0, arr, freq);

        return count;
    }
};