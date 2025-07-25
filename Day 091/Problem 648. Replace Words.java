import java.util.List;

class TrieNode {
    boolean isEnd;
    TrieNode[] children;
    final int R = 26;

    TrieNode() {
        isEnd = false;
        children = new TrieNode[R];
    }
}

class Trie {
    TrieNode root;
    Trie() {
        root = new TrieNode();
    }

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

    public String findShortestPrefix(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();

        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                return word;
            }

            node = node.children[curLetter - 'a'];
            prefix.append(curLetter);
            if (node.isEnd) {
                return prefix.toString();
            }
        }

        return prefix.toString();
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        // This problem can be formulated as finding the shortest prefix of each word in sentence that appeared in dictionary
        Trie trie = new Trie();
        for (String word : dictionary) {
            trie.insert(word);
        }

        StringBuilder result = new StringBuilder();
        for (String word : sentence.split(" ")) {
            result.append(trie.findShortestPrefix(word)).append(" ");
        }

        return result.toString().trim();
    }
}