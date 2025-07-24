class TrieNode {
    boolean isEnd;
    TrieNode[] children;
    final int R = 26;

    TrieNode() {this.isEnd = false; this.children = new TrieNode[R];}
}

class Trie {
    TrieNode root;
    Trie() {this.root = new TrieNode();}

    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                node.children[curLetter - 'a'] = new TrieNode();
            }

            node = node.children[curLetter - 'a'];
        }

        node.isEnd = true;
        return;
    }

    private int countChildren(TrieNode node) {
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (node.children[i] == null) continue;
            result++;
        }

        return result;
    }

    public String findLongestPrefix(String word) {
        StringBuilder prefix = new StringBuilder();
        TrieNode node = root;

        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.children[curLetter - 'a'] != null && countChildren(node) == 1 && !node.isEnd) {
                prefix.append(curLetter);
                node = node.children[curLetter - 'a'];
            } else {
                break;
            }
        }

        return prefix.toString();
    }
}

class Solution {
    public String longestCommonPrefix(String[] strs) {
        Trie trie = new Trie();
        for (String str : strs) {
            trie.insert(str);   
        }

        return trie.findLongestPrefix(strs[0]);
    }
}