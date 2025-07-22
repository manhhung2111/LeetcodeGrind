#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        bool isWord = false;
        vector<Node*> children = vector<Node*>(26, nullptr);
    } *root, *curr;

    void dfsWithPrefix(Node *curr, string &word, vector<string> &words) {
        if (words.size() == 3) {
            return;
        }

        if (curr->isWord) {
            words.push_back(word);
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (curr->children[c - 'a']) {
                word += c;
                dfsWithPrefix(curr->children[c - 'a'], word, words);
                word.pop_back();
            }
        }
    }

public:
    Trie() {
        this->root = new Node();
    }

    void insert(string &s) {
        curr = root;

        for (char &c : s) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }

    vector<string> getWordsStartWith(string& prefix) {
        curr = root;

        vector<string> result;
        // Move curr to the end of prefix in its trie representation.
        for (char &c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return result;
            }

            curr = curr->children[c - 'a'];
        }

        dfsWithPrefix(curr, prefix, result);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        vector<vector<string>> result;

        // Add all words to trie
        for (string &word : products) {
            trie.insert(word);
        }

        string prefix = "";
        for (char &c : searchWord) {
            prefix.push_back(c);
            result.push_back(trie.getWordsStartWith(prefix));
        }

        return result;
    }
};