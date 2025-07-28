import java.util.HashMap;
import java.util.Map;

class TrieNode {
    int val;
    TrieNode[] children;
    final int R = 26;

    TrieNode() {this.val = 0; this.children = new TrieNode[R];}
}


class MapSum {
    TrieNode root;
    Map<String, Integer> map;

    public MapSum() {
        root = new TrieNode();
        map = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        int delta = val - map.getOrDefault(key, 0);
        map.put(key, val);

        TrieNode node = root;
        node.val += delta;

        for (int i = 0; i < key.length(); i++) {
            char curLetter = key.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                node.children[curLetter - 'a'] = new TrieNode();
            }

            node = node.children[curLetter - 'a'];
            node.val += delta;
        }
    }
    
    public int sum(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char curLetter = prefix.charAt(i);
            if (node.children[curLetter - 'a'] == null) {
                return 0;
            }

            node = node.children[curLetter - 'a'];
        }

        return node.val;
    }
}