#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	bool isPalindrome(string &s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i++] != s[j--]) {
				return false;
			}
		}

		return true;
	}

	int result = 0;
	void dfs(int index, string &s, string &s1, string &s2) {
		if (index >= s.size()) {
			if (isPalindrome(s1) && isPalindrome(s2)) {
				int s1Size = s1.size(), s2Size = s2.size();
				result = max(result, s1Size * s2Size);
			}
			return;
		}

		s1.push_back(s[index]);
		dfs(index + 1, s, s1, s2);
		s1.pop_back();

		s2.push_back(s[index]);
		dfs(index + 1, s, s1, s2);
		s2.pop_back();

		dfs(index + 1, s, s1, s2);
	}

    int maxProduct(string s) {
        string s1 = "", s2 = "";
		dfs(0, s, s1, s2);

		return result;
    }
};