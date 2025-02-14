#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlphanumeric(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }

        if (c >= '0' && c <= '9') {
            return true;
        }

        return false;
    }


    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);

            if (!isAlphanumeric(s[i])) {
                i++;
            } else if (!isAlphanumeric(s[j])) {
                j--;
            } else {
                if (s[i] == s[j]) {
                    i++; j--;
                } else {
                    return false;
                }
            }


        }

        return true;
    }
};