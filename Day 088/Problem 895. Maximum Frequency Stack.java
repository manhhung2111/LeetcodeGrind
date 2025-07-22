import java.util.HashMap;
import java.util.Stack;

class FreqStack {
    HashMap<Integer, Integer> freqMap = new HashMap<>();
    HashMap<Integer, Stack<Integer>> map = new HashMap<>();
    int maxFreq = 0;

    public FreqStack() {
        
    }
    
    public void push(int val) {
        int f = freqMap.getOrDefault(val, 0) + 1;
        
        maxFreq = Math.max(maxFreq, f);
        freqMap.put(val, f);
        
        if (!map.containsKey(f)) {
            map.put(f, new Stack<>());
        }
        map.get(f).push(val);
    }
    
    public int pop() {
        int result = map.get(maxFreq).pop();
        freqMap.put(result, maxFreq - 1);

        if (map.get(maxFreq).isEmpty()) {
            maxFreq--;
        }

        return result;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */