import java.util.Stack;

class Solution {
    public int maximumGain(String s, int x, int y) {
        int result = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char curLetter = s.charAt(i);
            if (!stack.empty() && stack.peek() == 'a' && curLetter == 'b') {
                result += x;
                stack.pop();
            } else if (!stack.empty() && stack.peek() == 'b' && curLetter == 'a') {
                result += y;
                stack.pop();
            } else {
                stack.push(curLetter);
            }
        }

        return result;
    }
}