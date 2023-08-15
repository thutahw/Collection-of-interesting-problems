
import java.util.Stack;

/**
 * Given a string s and a character c, return a new list of integers of the same length as s where for each index i its value is set the closest distance of s[i] to c.
 * You can assume c exists in s. Constraints n ≤ 100,000 where n is the length of s Example 1 Input s = "aabaab" c = "b" Output [2, 1, 0, 1, 1, 0]
 */

public class ClosestDistToChar {

    public static void main(String[] args) {
        String s = "cccccccccc";
        char c = 'c';
        for (int a : findDist(s, c)) {
            System.out.print(a + " ");
        }
    }
    static int[] findDist(String s, char c) {
        int n = s.length();
        int[] result = new int[n];
        if (n == 0) {
            return result;
        }
        Stack<Integer> stack = new Stack<>();
        // get the positions of character c
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == c) {
                stack.push(i);
            }
        }
        int currentPos = stack.pop();
        for (int i = 0; i < n; i++) {
            if (i == currentPos) {
                result[i] = 0;

            } else if (i > currentPos) {

                if (!stack.empty()) {
                    int nextPos = stack.peek();
                    int firstDist = i - currentPos;
                    int nextDist = nextPos - i;
                    if (nextDist < firstDist) {
                        currentPos = nextPos;
                        stack.pop();
                        result[i] = nextDist;
                    } else {
                        result[i] = firstDist;
                    }
                } else {
                    result[i] = i - currentPos;
                }

            } else {
                result[i] = currentPos - i;
            }
        }


        return result;
    }


}
