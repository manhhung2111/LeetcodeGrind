class Solution {
public:
    int diffCharacters(string str1, string str2) {
        int count = 0;

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                count++;
            }
        }

        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, bool> visited;

        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;

        int result = 1;
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                string node = q.front(); q.pop();
                for (int j = 0; j < wordList.size(); j++) {
                    if (diffCharacters(node, wordList[j]) == 1 && visited[wordList[j]] == false) {
                        q.push(wordList[j]);
                        if (wordList[j] == endWord) {
                            return ++result;
                        }
                        visited[wordList[j]] = true;
                    }
                }
            }

            result++;
        }

        return 0;
    }
};