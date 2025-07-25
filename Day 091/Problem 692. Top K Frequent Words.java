import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> countMap = new HashMap<>();
        for (String word : words) {
            countMap.put(word, countMap.getOrDefault(word, 0) + 1);
        }

        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a.getValue().equals(b.getValue())) {
                    return b.getKey().compareTo(a.getKey()); // greater lex come first
                } else {
                    return a.getValue() - b.getValue(); // min heap
                }
            }
        );

        for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
            pq.offer(entry);
            if (pq.size() > k) {
                pq.remove();
            }
        }

        List<String> result = new ArrayList<>();
        while (!pq.isEmpty()) {
            result.add(pq.poll().getKey());
        }

        Collections.reverse(result);
        return result;
    }
}