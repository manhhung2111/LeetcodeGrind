class TrieNode {
    boolean isEnd;
    TrieNode[] children;
    final int R = 26;

    TrieNode() {this.isEnd = false; this.children = new TrieNode[R];}
}

class Trie {
    TrieNode root;
    public Trie() {
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
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                return false;
            }

            node = node.children[curLetter - 'a'];
        }

        return node.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char curLetter = prefix.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                return false;
            }

            node = node.children[curLetter - 'a'];
        }

        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */